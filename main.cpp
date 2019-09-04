#include "mainwindow.h"
#include <QApplication>
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<iostream>
/**
 * @brief Making a node as desired for trie data structure
 * 
 */
struct node
{
 QString meaning="Invalid word";
bool is_end=false;
struct node* child[26];
};
static struct node* head  = new node();
/**
 * @brief Method to insert the word along with its meaning in trie
 * 
 * @param word word which will be searched in dictionary
 * @param means meaning of the word
 */
void insert(QString word,QString means)
{
node * current = head;
int index;
for(int i=0;i<word.length();i++)
{
     index = word.at(i).toLatin1()-65;
    if(!(current->child[index]))
    current->child[index]= new node();
    current=  current->child[index];
}
current->is_end = true;
current->meaning = means;
}
/**
 * @brief Method to Search the string in Dictionary
 * 
 * @param word Word to be searched
 * @return QString If the word is valid its meaning is returned
 */
QString search(QString word)
{
node * current = head;
for(int i=0;i<word.length();i++)
{
if(!(current->child[word.at(i).toLatin1()-65]))
return  "Invalid word";
current = current->child[word.at(i).toLatin1()-65];
}
return current->meaning;}

static QString text;
static QString c,b;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("C:/Users/ANMOLKHEMUKA/Documents/Dictionary/data.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
    }
    QTextStream in (&file);
      while (!in.atEnd())  {
         text=in.readLine();
         QStringList list = text.split(",");
         c=list[0];
        b="";
for(int i=1;i<list.size();i++){
    b=b+list[i];
if(i<list.size()-1){
    b+=",";}
}
insert(c,b);
      }

    file.close();


    MainWindow w;

    w.show();

    return a.exec();
}

void MainWindow::on_pushButton_clicked()
{
    QString word = ui->plainTextEdit->toPlainText();
 QString means = search(word);
 ui->textBrowser->setText(means);
}
