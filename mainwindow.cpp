#include <QtGui>
#include "mainwindow.h"
#include "finddialog.h"
#include "sortdialog.h"
#include "gotocelldialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spreadsheet = new Spreadsheet;
    setCentralWidget(Spreadsheet);

    createActions();
    createMenus();
    createContextMenu();
    createToolBar();
    createStatusBar();

    readSettings();

    findDialog = 0;

    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");
}
void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/images/new.png"));
    newAction->setShortcut(QKeySequence::New);  //指定快捷键
    newAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open"),this);
    openAction->setIcon(QIcon(":/images/open.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("open a file"));
    connect(openAction, SIGNAL(triggered()), this ,SLOT(open()));

    saveAction = new QAction(tr("&Save"),this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("save a file"));
    connect(saveAction, SIGNAL(triggered()), this ,SLOT(save()));

    saveAsAction = new QAction(tr("&SaveAs"),this);
    saveAsAction->setIcon(QIcon(":/images/saveAs.png"));
    saveAsAction->setShortcut(QKeySequence::Save);
    saveAsAction->setStatusTip(tr("saveAs a file"));
    connect(saveAsAction, SIGNAL(triggered()), this ,SLOT(saveAs()));

    for(int i = 0; i < MaxRecentFiles; i++){
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(opeanRecentFile()));

        exitAction = new QAction(tr("E&xit"), this);
        exitAction->setShortcut(tr("Ctel+Q"));
        exitAction->setStatusTip(tr("Exit the app"));
        connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

        selectAllAction = new QAction(tr("&All"), this);
        selectAllAction->setShortcut(QKeySequence::SelectAll);
        selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
        connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));  //selectAll()函数原型？？？


        /* show grid*/
        showGridAction = new QAction(tr("&Show Grid"),this);
        showGridAction->setCheckable(true);
        showGridAction->setChecked(spreadsheet->showGrid());
        showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
        connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

        aboutQtAction = new QAction(tr("About &Qt"), this);
        connect(aboutQtAction, SIGNAL(triggered()),qApp, SLOT(aboutQt()));
    }




}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));  //已给定文本创建一个ＱＭenu的窗口部件，并添加到菜单栏,menuBar（）函数返回一个指向ＱＭenuBar的指针．菜单栏会在第一次调用该函数的时候创建出来．
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator(); //插入间隔器（separator）
    for(int i = 0; i < MaxRecentFiles; ++i)
        fileMenu->addAction(recentFileActions[i]);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));
    selectSubMenu->addAction(selectAllAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectRowAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalcAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);

}

void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBar()  //工具栏
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);

}
void MainWindow::createStatusBar()
{
    locationLabel = new QLabel(" W999 ");
    locationLabel->setAlignment(Qt::AlignCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);
    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);

    connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(updateStatusBar()));
            connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));
    updateStatusBar();
}
void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}
void MainWindow::spreadsheetModified()
{
    setWindowModified(true);
    updateStatusBar();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    if (okToContinue())
    {
        spreadsheet->clear();
        setCurrentFile("");
    }
}
bool MainWindow::okToContinue()
{
    if (isWindowModified())
    {
        int r = QMessageBox::warning(this, tr("Spreadsheet"), tr("The document has been modifid.\Do you want to save your changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (r == QMessageBox::Yes){
            return save();
        } else if (r == QMessageBox::Cancel){
            return false;
        }
        return true;
    }
}

void MainWindow::open()
{
    if (okToContinue()){
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open SPreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    if (!spreadsheet->readFile(fileName)){
        statusBar()->showMessage(tr("Loading canceled"), 2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    return true;
}
bool MainWindow::save()
{
    if (curFile.isEmpty()){
        return saveAs();
    }else{
        return saveFile(curFile);
    }
}
bool MainWindow::saveFile(const QString &fileName)
{
    if (!spreadsheet->writeFile(fileName)){
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"), ".", tr("Spreadsheet file (*.sp)"));
    if (fileName.isEmpty())
        return false;
    return saveFile(fileName);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (okToContinue()){
        writeSettings();
        event->accept();
    }else
        event->ignore();
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);

    QString shownName = tr("Untitled");
    if (!curFile.isEmpty()){
        shownName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);

    while (i.hasNext()){
        if ( !QFile::exists(i.next()))
            i.remove();
    }

    for ( int j = 0; j < MaxRecentFiles; ++i){
        if (j < recentFiles.count()){
            QString text = tr("&%1 %2").arg(j + i).arg(strippedName(recentFiles[j]));
            recentFiles[j]->setText(text);
            recentFiles[j]->setData(recentFiles[j]);
            recentFiles[j]->setVisible(true);
        }else
            recentFiles[j]->setVisible(false);
    }
    separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::opeanRecentFile()
{
    if(okToContinue()){
        QAction* action = qobject_cast<QAction *>(sender());
        if (action)
            loadFile(action->data().toString());
    }
}
