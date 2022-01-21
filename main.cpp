/***********************************************************************
*
* Copyright (c) 2021-2022 Barbara Geller and Ansel Sermersheim
*
* This example is free software, released under the BSD 2-Clause license.
* For license details refer to LICENSE provided with this project.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* https://opensource.org/licenses/BSD-2-Clause
*
***********************************************************************/

#include <QtCore>
#include <QtGui>


int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   QWidget *mainWindow = new QWidget();
   mainWindow->setMinimumSize(700, 350);

   QPushButton *pb1 = new QPushButton();
   pb1->setText("Close");

   QProgressBar *progress1 = new QProgressBar();
   
   QSlider *slider1 = new QSlider();

   QHBoxLayout *layout1 = new QHBoxLayout();
   layout1->addStretch();
   layout1->addWidget(progress1);
   layout1->addSpacing(10);
   layout1->addWidget(slider1);
   layout1->addStretch();

   QHBoxLayout *layout2 = new QHBoxLayout();
   layout2->addStretch();
   layout2->addWidget(pb1);
   layout2->addStretch();

   QVBoxLayout *layoutMain = new QVBoxLayout(mainWindow);
   layoutMain->addLayout(layout1);
   layoutMain->addSpacing(10);
   layoutMain->addLayout(layout2);

   QObject::connect(slider1, QAbstractSlider::valueChanged, progress1, QProgressBar::setValue);
   QObject::connect(pb1, &QPushButton::clicked, mainWindow, &QWidget::close);

   mainWindow->show();

   return app.exec();
}

