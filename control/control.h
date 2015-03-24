#ifndef CONTROL_H
#define CONTROL_H

#include <QtWidgets/QWidget>
#include "ui_control.h"

class control : public QWidget
{
	Q_OBJECT

public:
	control(QWidget *parent = 0);
	~control();

private:
	Ui::controlClass ui;
};

#endif // CONTROL_H
