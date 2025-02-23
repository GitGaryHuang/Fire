#ifndef NTABLEVIEW_H
#define NTABLEVIEW_H

#include <QTableView>

//! [Widget definition]
class NTableView : public QTableView {
    Q_OBJECT

public:
    NTableView(QAbstractItemModel * model, QWidget* parent=Q_NULLPTR);
    ~NTableView() override;

    int selectedSection() const { return selectedSection_; }

    /* User Custom Actions */
    void     addCustomAction(QAction *action);
    void     addCustomActions(QList<QAction *> actions);
    bool     removeCustomAction(QAction* action);


public slots:
    void freezeSection(int logicalIndex);
    void cancelFreeze();

protected:
    void resizeEvent(QResizeEvent *event) override;
    QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override;
    void scrollTo (const QModelIndex & index, ScrollHint hint = EnsureVisible) override;

private:
    void init();
    void updateFrozenTableGeometry();
    //
    QTableView *frozenTableView;
    int         selectedSection_;
    QList<QAction*> userActions_;


private slots:
    void updateSectionWidth(int logicalIndex, int oldSize, int newSize);
    void updateSectionHeight(int logicalIndex, int oldSize, int newSize);
    void onHHeaderCtxMenuRequested(QPoint pos);

};
//! [Widget definition]
#endif // NTableView_H
