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

   QPushButton *pb2 = new QPushButton();
   pb2->setText("set");


   QProgressBar *progress1 = new QProgressBar();

   QSpinBox *spinbox1 = new QSpinBox();
   spinbox1->setValue(0);
   spinbox1->setRange(0,3);

   QCheckBox *checkbox1 = new QCheckBox();
   

   QLineEdit *lineedit1 = new QLineEdit();
  
   QSlider *slider1 = new QSlider();
   slider1->setOrientation(Qt::Orientation(0x1));
   slider1->setRange(0,100);
   slider1->setTickPosition(QSlider::NoTicks);

   
   QHBoxLayout *layout1 = new QHBoxLayout();
   layout1->addStretch();
   layout1->addWidget(progress1);
   layout1->addSpacing(10);
   layout1->addWidget(slider1);
   layout1->addStretch();

   QHBoxLayout *layout2 = new QHBoxLayout();
   layout2->addStretch();
   layout2->addWidget(pb2);
   layout2->addSpacing(10);
   layout2->addWidget(spinbox1);
   layout2->addSpacing(10);
   layout2->addWidget(checkbox1);
   layout2->addSpacing(10);
   layout2->addWidget(lineedit1);
   layout2->addStretch();

   QHBoxLayout *layout3 = new QHBoxLayout();
   layout3->addStretch();
   layout3->addWidget(pb1);
   layout3->addStretch();

   QVBoxLayout *layoutMain = new QVBoxLayout(mainWindow);
   layoutMain->addLayout(layout1);
   layoutMain->addSpacing(25);
   layoutMain->addLayout(layout2);
   layoutMain->addSpacing(50);
   layoutMain->addLayout(layout3);


   QObject::connect(slider1, &QAbstractSlider::valueChanged, progress1, &QProgressBar::setValue);
   QObject::connect(pb1, &QPushButton::clicked, mainWindow, &QWidget::close);
   QObject::connect(spinbox1, cs_mp_cast<int>(&QSpinBox::valueChanged), slider1, [slider1,spinbox1,checkbox1](){
           int temp = spinbox1->value();
           if(checkbox1->checkState() == 2)
           {
           slider1->setTickPosition(QSlider::TickPosition(temp));
           }
   } );
   QObject::connect(checkbox1, &QCheckBox::stateChanged, slider1, [slider1,spinbox1,checkbox1](){
        if(checkbox1->checkState() == 2)
        {
            int temp = spinbox1->value();
            slider1->setTickPosition(QSlider::TickPosition(temp));
        }
        else
        {
            slider1->setTickPosition(QSlider::NoTicks);
         }
      } );
   QObject::connect(pb2, &QPushButton::clicked, lineedit1, [lineedit1,progress1](){
      int temp = progress1->value();	
      if(temp == 100)
      {
         lineedit1->setText("100% YAY!!11!11!");
      }
      else
      {
         lineedit1->setText("100% not reached yet");
      }
   });
   

   mainWindow->show();


   return app.exec();
}


