#include "window_removebook.h"
#include "ui_window_removebook.h"
#include <QJsonObject>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QJsonParseError>
#include<QJsonArray>
#include<QJsonValueRef>
#define AddedBooks ":/Data/RowData/AddedBooks.json"
Window_RemoveBook::Window_RemoveBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window_RemoveBook)
{
    ui->setupUi(this);
}

Window_RemoveBook::~Window_RemoveBook()
{
    delete ui;
}

void Window_RemoveBook::on_pushButton_RemoveBook_clicked()
{
    const QString & BookId = ui->lineEdit_BookId->text();
//    QFile file("/home/nilsa/Documents/AP/LibraryManagementSystem/V1.1/Login/AddedBooks.json"); // json file
//    if( !file.open( QIODevice::ReadWrite ) ) //write json content to file.
//    {
//        qDebug()<<"error opening file for removing the book.\n";
//    }
//     QJsonDocument jsonDoc = QJsonDocument::fromJson( file.readAll() );
////    char book_id[30];
////    strcpy(book_id,BookId);
////      jsonDoc.remove(BookId);
//      QJsonArray jArr = jsonDoc.array();
////      remove(jArr.find(BookId));
//      QJsonObject element [jArr.count];
//      for(int i=0;i<jArr.count();i++) {
//      element[i] = jArr.at(i).toObject();
//      }
////      qDebug() << element.value("number").toInt();
//      QJsonDocument doc( jArr );

//      file.write(doc.toJson());
//      file.close();
////    file.write(doc.toJson());
//    file.close();


     QFile AddedBooksFile(AddedBooks);
    AddedBooksFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QJsonParseError JsonParseError;
    QJsonDocument JsonDocument = QJsonDocument::fromJson(AddedBooksFile.readAll(), &JsonParseError);

    AddedBooksFile.close();

    QJsonObject RootObject = JsonDocument.object();
    QJsonValueRef ArrayRef = RootObject.find(BookId).value();
    QJsonArray Array = ArrayRef.toArray();

    QJsonArray::iterator ArrayIterator = Array.begin();
    QJsonValueRef ElementOneValueRef = ArrayIterator[0];

    QJsonObject ElementOneObject = ElementOneValueRef.toObject();

    // Make modifications to ElementOneObject
    ElementOneObject=QJsonObject();

    ElementOneValueRef = ElementOneObject;
    ArrayRef = Array;
    JsonDocument.setObject(RootObject);

    AddedBooksFile.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    AddedBooksFile.write(JsonDocument.toJson());
    AddedBooksFile.close();
}
