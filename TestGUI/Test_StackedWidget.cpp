//2018/03/13
//Chao

#include "Test_StackedWidget.h"
#include <QHBoxLayout>

Test_StackedWidget::Test_StackedWidget(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle(tr("StackedWidget"));
	list = new QListWidget(this);
	list->insertItem(0, tr("Window1"));
	list->insertItem(1, tr("Window2"));
	list->insertItem(2, tr("Window3"));

	label1 = new QLabel(tr("WindowTest1"));
	label2 = new QLabel(tr("WindowTest2"));
	label3 = new QLabel(tr("WindowTest3"));

	stack = new QStackedWidget(this);
	stack->addWidget(label1);
	stack->addWidget(label2);
	stack->addWidget(label3);

	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	mainLayout->setMargin(5);//Set window margin
	mainLayout->setSpacing(5);//Set object space
	mainLayout->addWidget(list);
	mainLayout->addWidget(stack, 0, Qt::AlignCenter);
	mainLayout->setStretchFactor(list, 1);
	mainLayout->setStretchFactor(stack,3);

	connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));
}

Test_StackedWidget::~Test_StackedWidget()
{

}
