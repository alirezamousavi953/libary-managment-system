/********************************************************************************
** Form generated from reading UI file 'window_member.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_MEMBER_H
#define UI_WINDOW_MEMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Member
{
public:
    QSplitter *splitter;
    QLabel *label_RentedBooks;
    QTableWidget *tableWidget_RentedBooks;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_Logout;
    QPushButton *pushButton_ViewAccount;
    QPushButton *pushButton_UpdateAccount;
    QPushButton *pushButton_ChangePassword;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_ReturnBook;
    QPushButton *pushButton_RemoveReservation;
    QPushButton *pushButton_RenewBook;
    QPushButton *pushButton_ReserveBook;
    QPushButton *pushButton_Search;

    void setupUi(QDialog *Window_Member)
    {
        if (Window_Member->objectName().isEmpty())
            Window_Member->setObjectName(QStringLiteral("Window_Member"));
        Window_Member->resize(841, 407);
        splitter = new QSplitter(Window_Member);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(230, 70, 281, 291));
        splitter->setOrientation(Qt::Vertical);
        label_RentedBooks = new QLabel(splitter);
        label_RentedBooks->setObjectName(QStringLiteral("label_RentedBooks"));
        splitter->addWidget(label_RentedBooks);
        tableWidget_RentedBooks = new QTableWidget(splitter);
        if (tableWidget_RentedBooks->columnCount() < 2)
            tableWidget_RentedBooks->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_RentedBooks->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_RentedBooks->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_RentedBooks->setObjectName(QStringLiteral("tableWidget_RentedBooks"));
        splitter->addWidget(tableWidget_RentedBooks);
        widget = new QWidget(Window_Member);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(720, 10, 109, 135));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Logout = new QPushButton(widget);
        pushButton_Logout->setObjectName(QStringLiteral("pushButton_Logout"));

        verticalLayout_2->addWidget(pushButton_Logout);

        pushButton_ViewAccount = new QPushButton(widget);
        pushButton_ViewAccount->setObjectName(QStringLiteral("pushButton_ViewAccount"));

        verticalLayout_2->addWidget(pushButton_ViewAccount);

        pushButton_UpdateAccount = new QPushButton(widget);
        pushButton_UpdateAccount->setObjectName(QStringLiteral("pushButton_UpdateAccount"));

        verticalLayout_2->addWidget(pushButton_UpdateAccount);

        pushButton_ChangePassword = new QPushButton(widget);
        pushButton_ChangePassword->setObjectName(QStringLiteral("pushButton_ChangePassword"));

        verticalLayout_2->addWidget(pushButton_ChangePassword);

        widget1 = new QWidget(Window_Member);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(521, 160, 124, 170));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_ReturnBook = new QPushButton(widget1);
        pushButton_ReturnBook->setObjectName(QStringLiteral("pushButton_ReturnBook"));

        verticalLayout->addWidget(pushButton_ReturnBook);

        pushButton_RemoveReservation = new QPushButton(widget1);
        pushButton_RemoveReservation->setObjectName(QStringLiteral("pushButton_RemoveReservation"));

        verticalLayout->addWidget(pushButton_RemoveReservation);

        pushButton_RenewBook = new QPushButton(widget1);
        pushButton_RenewBook->setObjectName(QStringLiteral("pushButton_RenewBook"));

        verticalLayout->addWidget(pushButton_RenewBook);

        pushButton_ReserveBook = new QPushButton(widget1);
        pushButton_ReserveBook->setObjectName(QStringLiteral("pushButton_ReserveBook"));

        verticalLayout->addWidget(pushButton_ReserveBook);

        pushButton_Search = new QPushButton(widget1);
        pushButton_Search->setObjectName(QStringLiteral("pushButton_Search"));

        verticalLayout->addWidget(pushButton_Search);


        retranslateUi(Window_Member);

        QMetaObject::connectSlotsByName(Window_Member);
    } // setupUi

    void retranslateUi(QDialog *Window_Member)
    {
        Window_Member->setWindowTitle(QApplication::translate("Window_Member", "Dialog", Q_NULLPTR));
        label_RentedBooks->setText(QApplication::translate("Window_Member", "                          RentedBooks", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_RentedBooks->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Window_Member", "BookName", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_RentedBooks->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Window_Member", "RentedUntil", Q_NULLPTR));
        pushButton_Logout->setText(QApplication::translate("Window_Member", "Logout", Q_NULLPTR));
        pushButton_ViewAccount->setText(QApplication::translate("Window_Member", "ViewAccount", Q_NULLPTR));
        pushButton_UpdateAccount->setText(QApplication::translate("Window_Member", "UpdateAccount", Q_NULLPTR));
        pushButton_ChangePassword->setText(QApplication::translate("Window_Member", "ChangePassword", Q_NULLPTR));
        pushButton_ReturnBook->setText(QApplication::translate("Window_Member", "ReturnBook", Q_NULLPTR));
        pushButton_RemoveReservation->setText(QApplication::translate("Window_Member", "RemoveReservation", Q_NULLPTR));
        pushButton_RenewBook->setText(QApplication::translate("Window_Member", "RenewBook", Q_NULLPTR));
        pushButton_ReserveBook->setText(QApplication::translate("Window_Member", "ReserveBook", Q_NULLPTR));
        pushButton_Search->setText(QApplication::translate("Window_Member", "Search", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Window_Member: public Ui_Window_Member {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_MEMBER_H
