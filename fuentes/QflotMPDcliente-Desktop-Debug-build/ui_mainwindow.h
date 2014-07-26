/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 25. Jul 23:47:04 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnConectar;
    QPushButton *btnEsperarCambios;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnEstado;
    QPushButton *btnEstadisticas;
    QPushButton *btnItemActual;
    QPushButton *btnInfoLista;
    QPushButton *btnListaComandos;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnTiposTags;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(742, 514);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnConectar = new QPushButton(centralWidget);
        btnConectar->setObjectName(QString::fromUtf8("btnConectar"));

        horizontalLayout_3->addWidget(btnConectar);

        btnEsperarCambios = new QPushButton(centralWidget);
        btnEsperarCambios->setObjectName(QString::fromUtf8("btnEsperarCambios"));

        horizontalLayout_3->addWidget(btnEsperarCambios);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnEstado = new QPushButton(centralWidget);
        btnEstado->setObjectName(QString::fromUtf8("btnEstado"));

        horizontalLayout->addWidget(btnEstado);

        btnEstadisticas = new QPushButton(centralWidget);
        btnEstadisticas->setObjectName(QString::fromUtf8("btnEstadisticas"));

        horizontalLayout->addWidget(btnEstadisticas);

        btnItemActual = new QPushButton(centralWidget);
        btnItemActual->setObjectName(QString::fromUtf8("btnItemActual"));

        horizontalLayout->addWidget(btnItemActual);

        btnInfoLista = new QPushButton(centralWidget);
        btnInfoLista->setObjectName(QString::fromUtf8("btnInfoLista"));

        horizontalLayout->addWidget(btnInfoLista);

        btnListaComandos = new QPushButton(centralWidget);
        btnListaComandos->setObjectName(QString::fromUtf8("btnListaComandos"));

        horizontalLayout->addWidget(btnListaComandos);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnTiposTags = new QPushButton(centralWidget);
        btnTiposTags->setObjectName(QString::fromUtf8("btnTiposTags"));

        horizontalLayout_2->addWidget(btnTiposTags);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnConectar->setText(QApplication::translate("MainWindow", "conectar", 0, QApplication::UnicodeUTF8));
        btnEsperarCambios->setText(QApplication::translate("MainWindow", "esperar cambios", 0, QApplication::UnicodeUTF8));
        btnEstado->setText(QApplication::translate("MainWindow", "estado", 0, QApplication::UnicodeUTF8));
        btnEstadisticas->setText(QApplication::translate("MainWindow", "estadisticas", 0, QApplication::UnicodeUTF8));
        btnItemActual->setText(QApplication::translate("MainWindow", "item actual", 0, QApplication::UnicodeUTF8));
        btnInfoLista->setText(QApplication::translate("MainWindow", "info lista", 0, QApplication::UnicodeUTF8));
        btnListaComandos->setText(QApplication::translate("MainWindow", "lista de comandos", 0, QApplication::UnicodeUTF8));
        btnTiposTags->setText(QApplication::translate("MainWindow", "tipos de tags permitidos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
