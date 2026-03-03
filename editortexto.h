#ifndef EDITORTEXTO_H
#define EDITORTEXTO_H

#include <QDialog>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "file.h"

class EditorTexto : public QDialog {
    Q_OBJECT
public:
    explicit EditorTexto(File* archivo, QWidget* parent = nullptr);
private slots:
    void guardar();
private:
    File* m_archivo;
    QPlainTextEdit* m_editor;
};

#endif
