#include "page_type_a.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qpushbutton.h>

page_type_a::page_type_a(QWidget* parent)
    : QWidget{parent}
{
}

page_type_a& page_type_a::layout_h()
{
    add_layout_helper(new QHBoxLayout{});
    return *this;
}

page_type_a &page_type_a::layout_v()
{
    add_layout_helper(new QVBoxLayout{});
    return *this;
}

page_type_a& page_type_a::layout_pop()
{
    add_layout_helper(new QVBoxLayout{});
    return *this;
}

page_type_a& page_type_a::button(const std::string& text)
{
    auto button1 = new QPushButton(QString::fromUtf8(text.c_str()));
    add_widget_helper(button1);
    return *this;
}

void page_type_a::add_layout_helper(QLayout* layout)
{
    if (!has_cur_layout()) {
        setLayout(layout);
        m_layout_stack.push(layout);
        return;
    }

    if (auto* box_layout = dynamic_cast<QBoxLayout*>(cur_layout()); box_layout != nullptr) {
        box_layout->addLayout(layout);
    }
    m_layout_stack.push(layout);
}

void page_type_a::add_widget_helper(QWidget *w)
{
    cur_layout()->addWidget(w);
}

QLayout* page_type_a::cur_layout() const
{
    if (m_layout_stack.empty()) {
        return nullptr;
    }
    return m_layout_stack.top();
}

bool page_type_a::has_cur_layout() const
{
    return cur_layout() != nullptr;
}

QLayout *page_type_a::default_layout()
{
    return new QVBoxLayout{};
}
