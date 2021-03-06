#include "window_editbook.h"
#include "ui_window_editbook.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <bits/stdc++.h>
#include <QDate>
#include <QString>
#include<QMessageBox>
#define AddedBooks "/home/nilsa/Documents/AP/LibraryManagementSystem/Login/RowData/AddedBooks.json"
#define accounts "/home/nilsa/Documents/AP/LibraryManagementSystem/Login/RowData/accounts.json"
Window_EditBook::Window_EditBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window_EditBook)
{
    ui->setupUi(this);
   // ui->la
    ui->label_Subject->hide();
    ui->label_BookName->hide();
    ui->label_AuthorName->hide();
    ui->lineEdit_Subject->hide();
    ui->lineEdit_BookName->hide();
    ui->lineEdit_AuthorName->hide();
    ui->pushButton_EditBook->hide();

}

Window_EditBook::~Window_EditBook()
{
    delete ui;
}

void Window_EditBook::on_pushButton_Search_clicked()
{
    //========================================
      //put this codes in if(id==found)!!!!!!

    ui->label_Subject->show();
    ui->label_BookName->show();
    ui->label_AuthorName->show();
    ui->lineEdit_Subject->show();
    ui->lineEdit_BookName->show();
    ui->lineEdit_AuthorName->show();
    ui->pushButton_EditBook->show();



    //=======================================
    QString BookId = ui->lineEdit_BookId->text();
    QFile AddedBooksFile(AddedBooks);
   AddedBooksFile.open(QIODevice::ReadWrite | QIODevice::Text);
   QByteArray B = AddedBooksFile.readAll();
   QJsonDocument D = QJsonDocument::fromJson(B);
   QJsonObject Obj = D.object();
   if(Obj.find(BookId)==Obj.end()){
       QMessageBox::warning(this," ","Book not found!");
       this->close();
       return;
   }
   AddedBooksFile.close();

   QJsonValueRef found_ref = Obj.find(BookId).value();
   QJsonObject found_obj= found_ref.toObject();
   QString BookName= found_obj["name"].toString();
   QString subject= found_obj["subject"].toString();
   QString date_added= found_obj["date_added"].toString();
   QString status= found_obj["status"].toString();
   QString author= found_obj["author"].toString();


   ui->lineEdit_Subject->setText(subject);
   ui->lineEdit_BookName->setText(BookName);
   ui->lineEdit_AuthorName->setText(author);
    //show these in the table of the UI please!

}

void Window_EditBook::on_pushButton_EditBook_clicked()
{
    QString NewBookName = ui->lineEdit_BookName->text();
    QString NewAuthor = ui->lineEdit_AuthorName->text();
    QString NewSubject = ui->lineEdit_Subject->text();
    QString BookId = ui->lineEdit_BookId->text();
    QFile AddedBooksFile(AddedBooks);
   AddedBooksFile.open(QIODevice::ReadWrite | QIODevice::Text);
   QByteArray B = AddedBooksFile.readAll();
   QJsonDocument D = QJsonDocument::fromJson(B);
   QJsonObject Obj = D.object();
   QJsonValueRef found_ref = Obj.find(BookId).value();
   QJsonObject found_obj= found_ref.toObject();
   QString date_added= found_obj["date_added"].toString();
   QJsonObject EditedBook = {   {"id", BookId},
                                  {"status", "available"},
                                  {"date_added", date_added},
                                  {"name", NewBookName},
                                  {"author", NewAuthor},
                                  {"subject", NewSubject}
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
