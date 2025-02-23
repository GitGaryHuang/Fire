#ifndef WINDOW_H
#define WINDOW_H
#include <QWidget>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QStandardItemModel;
class QCheckBox;
class QComboBox;
class QDateEdit;
class QMainWindow;
class QLabel;
class QLineEdit;
class QStringList;
class QVBoxLayout;

QT_END_NAMESPACE
class NFilterBar;
class NFindBar;
class NSortFilterProxyModel;
class NTableView;

class Filter : public QObject
{
    Q_OBJECT

};

//! [0]
class Window : public QWidget
{
    Q_OBJECT

public:
    Window();


private slots:
    void filter();
    void prev();
    void next();

    //
    void appendColumnNameToFilter();

private:
    NFindBar *nfindBar;
    NFilterBar *nfilterBar;
    NTableView *ntableView;
    NSortFilterProxyModel *nsortfilterproxyModel;

    QMainWindow *qmainWindow;
    QVBoxLayout *qvboxLayout;
    QStandardItemModel *sourceModel;
    QStringList header_list;
    void init_header_list(NSortFilterProxyModel *model);
    void global_filter();
};
//! [0]




#endif // WINDOW_H
