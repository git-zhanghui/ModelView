#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reimplementedtablemodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pModel = new ReimplementedTableModel();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setModel(m_pModel);
    connect(ui->addRow, &QPushButton::clicked, m_pModel, &ReimplementedTableModel::addRow);
    connect(ui->removeRow, &QPushButton::clicked, m_pModel, &ReimplementedTableModel::removeRow);
}

MainWindow::~MainWindow()
{
    delete ui;
}
