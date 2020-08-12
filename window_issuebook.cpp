#include "window_issuebook.h"
#include "ui_window_issuebook.h"
#include "window_addbook.h"
#include "ui_window_addbook.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <bits/stdc++.h>
#include <QDate>
#include <QString>
#include <QMessageBox>
#include<QDir>
//==============================================================================================
Window_IssueBook::Window_IssueBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window_IssueBook)
{
    ui->setupUi(this);
    ui->lineEdit_BookId->setFocus();
    ui->pushButton_IssueBook->hide();
}

Window_IssueBook::~Window_IssueBook()
{
    delete ui;
}

void Window_IssueBook::on_pushButton_search_clicked()
{
    QDir AddedBook;
    AddedBook.cd("..");
    AddedBook.cd("Login_MY_FINAL");
    AddedBook.cd("RowData");
    QFile  AddedBooksFile(AddedBook.path()+"/AddedBooks.json");
    QString BookId = ui->lineEdit_BookId->text();
   AddedBooksFile.open(QIODevice::ReadWrite | QIODevice::Text);
   QByteArray B = AddedBooksFile.readAll();
   QJsonDocument D = QJsonDocument::fromJson(B);
   QJsonObject Obj = D.object();

   AddedBooksFile.close();
   if(Obj.find(BookId)==Obj.end()){
        QMessageBox::warning(this," ","Book not found!");
        return;
   }
   ui->pushButton_search->hide();
   ui->pushButton_IssueBook->show();
//   QJsonObject empty ={};
   QJsonValueRef found_ref = Obj.find(BookId).value();
   QJsonObject found_obj= found_ref.toObject();
   QString BookName= found_obj["name"].toString();
   QString subject= found_obj["subject"].toString();
   QString date_added= found_obj["date_added"].toString();
   QString status= found_obj["status"].toString();
   QString author= found_obj["author"].toString();


}

void Window_IssueBook::on_pushButton_IssueBook_clicked()
{

    QString BookId = ui->lineEdit_BookId->text();
    QDir AddedBook;
    AddedBook.cd("..");
    AddedBook.cd("Login_MY_FINAL");
    AddedBook.cd("RowData");
    QFile  AddedBooksFile(AddedBook.path()+"/AddedBooks.json");
   AddedBooksFile.open(QIODevice::ReadWrite | QIODevice::Text);
   QByteArray B = AddedBooksFile.readAll();
   QJsonDocument D = QJsonDocument::fromJson(B);
   QJsonObject Obj = D.object();
   QJsonValueRef found_ref = Obj.find(BookId).value();
   QJsonObject found_obj= found_ref.toObject();
   QString BookName= found_obj["name"].toString();
   QString subject= found_obj["subject"].toString();

   QString status= found_obj["status"].toString();
   QString author= found_obj["author"].toString();
   QString date_added= found_obj["date_added"].toString();
   QJsonObject EditedBook = {   {"id", BookId},
                                  {"status", "issued"},
                                  {"date_added", date_added},
                                  {"name", BookName},
                                  {"author", author},
                                  {"subject", subject}
};
   AddedBooksFile.close();
    Obj.remove(BookId);
   Obj[BookId]=EditedBook;


   QJsonDocument doc( Obj );

   if( !AddedBooksFile.open( QIODevice::WriteOnly ) ) //write json content to file.
   {
       qDebug()<<"error opening file for write.\n";
   }

   AddedBooksFile.write(doc.toJson());
   AddedBooksFile.close();

       QMessageBox::information(this," ","Book edited successfully!");

}

