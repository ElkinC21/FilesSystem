#include "editortexto.h"

EditorTexto::EditorTexto(File* archivo, QWidget* parent)
    : QDialog(parent), m_archivo(archivo)
{
    setWindowTitle("Editando: " + QString::fromStdString(m_archivo->getName()));
    setMinimumSize(400, 300);

    QVBoxLayout* layout = new QVBoxLayout(this);
    m_editor = new QPlainTextEdit(this);


    m_editor->setPlainText(QString::fromStdString(*(m_archivo->getText())));

    QPushButton* btn = new QPushButton("Guardar Cambios", this);
    layout->addWidget(m_editor);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &EditorTexto::guardar);
}

void EditorTexto::guardar() {

    m_archivo->setText(m_editor->toPlainText().toStdString());
    accept();
}
