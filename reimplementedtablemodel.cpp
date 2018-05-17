#include "reimplementedtablemodel.h"

ReimplementedTableModel::ReimplementedTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_headData << QString("ID") << QString("Name") << QString("Infomation") << QString("Description");

    for(int nIndex(0); nIndex < 10; nIndex++)
    {
        Data d;
        d.Id = nIndex;
        d.name = QString::number(nIndex);
        d.infomation = QString::number(nIndex);
        d.description = QString::number(nIndex);
        m_data.append(d);
    }
}

QVariant ReimplementedTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(Qt::Horizontal == orientation && Qt::DisplayRole == role)
    {
        return m_headData[section];
    }

    return QVariant();
}

bool ReimplementedTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role))
    {
        emit headerDataChanged(orientation, section, section);
        return true;
    }

    return false;
}


int ReimplementedTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return m_data.count();
}

int ReimplementedTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
    {
        return 0;
    }

    return m_headData.count();
}

QVariant ReimplementedTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if(Qt::DisplayRole != role && Qt::EditRole != role)
    {
        return QVariant();
    }

    switch (index.column())
    {
    case 0:
        return m_data[index.row()].Id;
        break;
    case 1:
        return m_data[index.row()].name;
        break;
    case 2:
        return m_data[index.row()].infomation;
        break;
    case 3:
        return m_data[index.row()].description;
        break;
    default:
        break;
    }

    return QVariant();
}

bool ReimplementedTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    if (data(index, role) != value)
    {
        Data & d = m_data[index.row()];
        switch (index.column())
        {
        case 0:
            d.Id = value.toInt();
            break;
        case 1:
            d.name = value.toString();
            break;
        case 2:
            d.infomation = value.toString();
            break;
        case 3:
            d.description = value.toString();
            break;
        default:
            break;
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags ReimplementedTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool ReimplementedTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);

    Data d;
    d.Id = row;
    d.name = QString::number(row);
    d.infomation = QString::number(row);
    d.description = QString::number(row);
    m_data.append(d);

    endInsertRows();
    return true;
}

bool ReimplementedTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    //Implement!

    endInsertColumns();
    return true;
}

bool ReimplementedTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0)
    {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    m_data.takeLast();
    endRemoveRows();
    return true;
}

bool ReimplementedTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    //Implement!

    endRemoveColumns();
    return true;
}

void ReimplementedTableModel::addRow()
{
    insertRows(rowCount(), 1);
}

void ReimplementedTableModel::removeRow()
{
    removeRows(rowCount() - 1, 1);
}
