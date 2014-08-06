#include "myinputpanel.h"
#include <QPushButton>



MyInputPanel::MyInputPanel()
    : QWidget(0, Qt::Tool | Qt::FramelessWindowHint),
      lastFocusedWidget(0), shiftClick(false)
{
    form.setupUi(this);

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)),
            this, SLOT(saveFocusWidget(QWidget*,QWidget*)));

    signalMapper.setMapping(form.pushButton_a, form.pushButton_a);
    signalMapper.setMapping(form.pushButton_b, form.pushButton_b);
    signalMapper.setMapping(form.pushButton_c, form.pushButton_c);
    signalMapper.setMapping(form.pushButton_d, form.pushButton_d);
    signalMapper.setMapping(form.pushButton_e, form.pushButton_e);
    signalMapper.setMapping(form.pushButton_f, form.pushButton_f);
    signalMapper.setMapping(form.pushButton_g, form.pushButton_g);
    signalMapper.setMapping(form.pushButton_h, form.pushButton_h);
    signalMapper.setMapping(form.pushButton_i, form.pushButton_i);
    signalMapper.setMapping(form.pushButton_j, form.pushButton_j);
    signalMapper.setMapping(form.pushButton_k, form.pushButton_k);
    signalMapper.setMapping(form.pushButton_l, form.pushButton_l);
    signalMapper.setMapping(form.pushButton_m, form.pushButton_m);
    signalMapper.setMapping(form.pushButton_n, form.pushButton_n);
    signalMapper.setMapping(form.pushButton_o, form.pushButton_o);
    signalMapper.setMapping(form.pushButton_p, form.pushButton_p);
    signalMapper.setMapping(form.pushButton_q, form.pushButton_q);
    signalMapper.setMapping(form.pushButton_r, form.pushButton_r);
    signalMapper.setMapping(form.pushButton_s, form.pushButton_s);
    signalMapper.setMapping(form.pushButton_t, form.pushButton_t);
    signalMapper.setMapping(form.pushButton_u, form.pushButton_u);
    signalMapper.setMapping(form.pushButton_v, form.pushButton_v);
    signalMapper.setMapping(form.pushButton_w, form.pushButton_w);
    signalMapper.setMapping(form.pushButton_x, form.pushButton_x);
    signalMapper.setMapping(form.pushButton_x, form.pushButton_x);
    signalMapper.setMapping(form.pushButton_y, form.pushButton_y);
    signalMapper.setMapping(form.pushButton_z, form.pushButton_z);
    signalMapper.setMapping(form.pushButton_del, form.pushButton_del);
    signalMapper.setMapping(form.pushButton_enter, form.pushButton_enter);
    signalMapper.setMapping(form.pushButton_space, form.pushButton_space);
    signalMapper.setMapping(form.pushButton_num, form.pushButton_num);
    signalMapper.setMapping(form.pushButton_shift, form.pushButton_shift);

    connect(form.pushButton_a, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_b, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_c, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_d, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_e, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_f, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_g, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_h, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_i, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_j, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_k, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_l, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_m, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_n, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_o, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_p, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_q, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_r, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_s, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_t, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_u, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_v, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_w, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_x, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_y, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_z, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_enter, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_space, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_num, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_shift, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));
    connect(form.pushButton_del, SIGNAL(clicked()),
            &signalMapper, SLOT(map()));

    connect(&signalMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(buttonClicked(QWidget*)));
}


bool MyInputPanel::event(QEvent *e)
{
    switch (e->type()) {
    case QEvent::WindowActivate:
        if (lastFocusedWidget)
            lastFocusedWidget->activateWindow();
        break;
    default:
        break;
    }

    return QWidget::event(e);
}


void MyInputPanel::saveFocusWidget(QWidget * /*oldFocus*/, QWidget *newFocus)
{
    if (newFocus != 0 && !this->isAncestorOf(newFocus)) {
        lastFocusedWidget = newFocus;
    }
}
void MyInputPanel::setKeyboardCaps()
{
    form.pushButton_a->setText(form.pushButton_a->text().toUpper());
    form.pushButton_b->setText(form.pushButton_b->text().toUpper());
    form.pushButton_c->setText(form.pushButton_c->text().toUpper());
    form.pushButton_d->setText(form.pushButton_d->text().toUpper());
    form.pushButton_e->setText(form.pushButton_e->text().toUpper());
    form.pushButton_f->setText(form.pushButton_f->text().toUpper());
    form.pushButton_g->setText(form.pushButton_g->text().toUpper());
    form.pushButton_h->setText(form.pushButton_h->text().toUpper());
    form.pushButton_i->setText(form.pushButton_i->text().toUpper());
    form.pushButton_j->setText(form.pushButton_j->text().toUpper());
    form.pushButton_k->setText(form.pushButton_k->text().toUpper());
    form.pushButton_l->setText(form.pushButton_l->text().toUpper());
    form.pushButton_m->setText(form.pushButton_m->text().toUpper());
    form.pushButton_n->setText(form.pushButton_n->text().toUpper());
    form.pushButton_o->setText(form.pushButton_o->text().toUpper());
    form.pushButton_p->setText(form.pushButton_p->text().toUpper());
    form.pushButton_q->setText(form.pushButton_q->text().toUpper());
    form.pushButton_r->setText(form.pushButton_r->text().toUpper());
    form.pushButton_s->setText(form.pushButton_s->text().toUpper());
    form.pushButton_t->setText(form.pushButton_t->text().toUpper());
    form.pushButton_u->setText(form.pushButton_u->text().toUpper());
    form.pushButton_v->setText(form.pushButton_v->text().toUpper());
    form.pushButton_w->setText(form.pushButton_w->text().toUpper());
    form.pushButton_x->setText(form.pushButton_x->text().toUpper());
    form.pushButton_y->setText(form.pushButton_y->text().toUpper());
    form.pushButton_z->setText(form.pushButton_z->text().toUpper());

}
void MyInputPanel::setKeyboardLower()
{
    form.pushButton_a->setText(form.pushButton_a->text().toLower());
    form.pushButton_b->setText(form.pushButton_b->text().toLower());
    form.pushButton_c->setText(form.pushButton_c->text().toLower());
    form.pushButton_d->setText(form.pushButton_d->text().toLower());
    form.pushButton_e->setText(form.pushButton_e->text().toLower());
    form.pushButton_f->setText(form.pushButton_f->text().toLower());
    form.pushButton_g->setText(form.pushButton_g->text().toLower());
    form.pushButton_h->setText(form.pushButton_h->text().toLower());
    form.pushButton_i->setText(form.pushButton_i->text().toLower());
    form.pushButton_j->setText(form.pushButton_j->text().toLower());
    form.pushButton_k->setText(form.pushButton_k->text().toLower());
    form.pushButton_l->setText(form.pushButton_l->text().toLower());
    form.pushButton_m->setText(form.pushButton_m->text().toLower());
    form.pushButton_n->setText(form.pushButton_n->text().toLower());
    form.pushButton_o->setText(form.pushButton_o->text().toLower());
    form.pushButton_p->setText(form.pushButton_p->text().toLower());
    form.pushButton_q->setText(form.pushButton_q->text().toLower());
    form.pushButton_r->setText(form.pushButton_r->text().toLower());
    form.pushButton_s->setText(form.pushButton_s->text().toLower());
    form.pushButton_t->setText(form.pushButton_t->text().toLower());
    form.pushButton_u->setText(form.pushButton_u->text().toLower());
    form.pushButton_v->setText(form.pushButton_v->text().toLower());
    form.pushButton_w->setText(form.pushButton_w->text().toLower());
    form.pushButton_x->setText(form.pushButton_x->text().toLower());
    form.pushButton_y->setText(form.pushButton_y->text().toLower());
    form.pushButton_z->setText(form.pushButton_z->text().toLower());

}

void MyInputPanel::buttonClicked(QWidget *w)
{
    QPushButton *senderButton = qobject_cast<QPushButton *>(w);
    if("pushButton_del"== senderButton->objectName())
    {
        emit keyPressed(Qt::Key_Backspace);
    }
    else if ("pushButton_shift" == senderButton->objectName())
    {
        setKeyboardCaps();
        shiftClick = true;
    }
    else if ("pushButton_space" == senderButton->objectName())
    {
        emit keyPressed(Qt::Key_Space);
    }
    else if ("pushButton_enter" == senderButton->objectName())
    {
        emit keyPressed(Qt::Key_Enter);
    }
    else
    {
        QString text = senderButton->text();
        const QChar *chr = text.unicode();
        emit characterGenerated(*chr);
        if (shiftClick)
        {
            setKeyboardLower();
            shiftClick = false;
        }
    }
}
