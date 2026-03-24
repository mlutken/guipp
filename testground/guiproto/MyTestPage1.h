#pragma once

#include <QWidget>
#include <stack>
class QVBoxLayout;
class QHBoxLayout;

class my_test_page_1 : public QWidget
{
    Q_OBJECT
public:
    explicit my_test_page_1(QWidget* parent = nullptr);

    my_test_page_1&         layout_h    ();
    my_test_page_1&         layout_v    ();
    my_test_page_1&         layout_pop  ();


signals:
private:
    void                    add_layout_helper   (QLayout* layout);

    std::stack<QLayout*> m_layout_stack   {};

};
