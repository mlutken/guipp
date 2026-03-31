#pragma once

#include <QWidget>
#include <unordered_map>
#include <stack>
class QVBoxLayout;
class QHBoxLayout;

class page_type_a : public QWidget
{
    Q_OBJECT
public:
    explicit page_type_a(QWidget* parent = nullptr);

    page_type_a&        layout_h    ();
    page_type_a&        layout_v    ();
    page_type_a&        layout_pop  ();

    page_type_a&        button      (const std::string& text);

signals:
private:
    using layout_stack_t    = std::stack<QLayout*>;
    using widget_map_t      = std::unordered_map<std::string, QWidget*>;
''
    void                add_layout_helper   (QLayout* layout);
    // void                cur_layout          ();
    void                add_widget_helper   (QWidget* w);
    QLayout*            cur_layout          () const;
    bool                has_cur_layout      () const;
    static QLayout*     default_layout      ();

    layout_stack_t      m_layout_stack      {};
    widget_map_t        m_widget_map        {};
};
