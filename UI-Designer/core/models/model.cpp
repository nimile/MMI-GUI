#include "model.h"

haevn::core::models::Model::Model() : QObject(){
    m_scenegraph = new QList<QWidget*>();
    m_scripts = nullptr;
    loadScripts();
}

haevn::core::models::Model::~Model(){
    delete m_scenegraph;
    m_scenegraph = nullptr;

    delete m_scripts;
    m_scripts = nullptr;
}

void haevn::core::models::Model::loadScripts(){
    haevn::core::util::FileUtils fileHandler;
    if(m_scripts != nullptr){
        delete m_scripts;
    }
    m_scripts = fileHandler.loadScripts();
}

void haevn::core::models::Model::insertScript(QString name, QString path){
    m_scripts->insert(name, path);
}

QMap<QString, QString>* haevn::core::models::Model::getScripts(){
    return m_scripts;
}

QList<QWidget*>* haevn::core::models::Model::getScenegraph(){
    return m_scenegraph;
}


void haevn::core::models::Model::removeItem(QWidget* t_item){
    m_scenegraph->removeOne(t_item);
}

void haevn::core::models::Model::addItem(QWidget* t_item){
    if(t_item == nullptr){
        return;
    }
    m_scenegraph->insert(m_scenegraph->size() + 1, t_item);
}
