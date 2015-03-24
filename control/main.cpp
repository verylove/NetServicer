#include "control.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	control w;
	w.show();
	return a.exec();
}
