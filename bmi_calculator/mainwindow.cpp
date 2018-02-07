
/*
 * MainWindow class initializer, methods and slots.
 * Handles the signals with slots. Slots call Bmi class methods
 * that handle the BMI related calculations and class variables
 * manipulations.
*/

#include "bmi.hh"

#include "mainwindow.hh"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{   // Initialize GUI
    ui->setupUi(this);
    createActions();
    createMenus();
    reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Call reset method for Bmi class object
// and reset GUI.
void MainWindow::reset() {
    class_object_->reset();
    set_female();
    ui->height_slider->setValue(0);
    ui->weight_slider->setValue(0);

}

// Quit the application.
void MainWindow::quit() {
    QApplication::quit();
}

// Set the Bmi class object's gender to female
// by calling change_gender method.
// Adjust GUI to match.
void MainWindow::set_female() {
    class_object_->change_gender(0);
    female_act->setChecked(true);
    ui->gender_label->setText("Female");
    interpret();
}

// Set the Bmi class object's gender to male
// by calling change_gender method.
// Adjust GUI to match.
void MainWindow::set_male() {
    class_object_->change_gender(1);
    male_act->setChecked(true);
    ui->gender_label->setText("Male");
    interpret();
}

// Set Bmi class objects height to match
// the value in height slider.
// As the QSlider and QSpinBox change the value
// together, only one method is needed for one
// slider-box pair.
void MainWindow::set_height() {
    double height = ui->height_slider->value();
    class_object_->change_height(height);
}

// Set Bmi class objects weight to match
// the value in weight slider.
// As the QSlider and QSpinBox change the value
// together, only one method is needed for one
// slider-box pair.
void MainWindow::set_weight() {
    int weight = ui->weight_slider->value();
    class_object_->change_weight(weight);

}

// Call Bmi class' method calculate_bmi() to
// calculate BMI. Update GUI.
void MainWindow::calculate_bmi(){
    class_object_->calculate_bmi();
    if (class_object_->get_height() > 0 && class_object_->get_weight() > 0 ) {
        ui->bmi_label->setText(QString::number(class_object_->get_bmi()));
    }else {
        ui->bmi_label->setText("-");
    }
}

// Call Bmi class' method interpret() to
// interpret BMI. Update GUI.
void MainWindow::interpret() {
    class_object_->interpret();
    if (class_object_->get_height() > 0 && class_object_->get_weight() > 0 ) {
        QString interpretation = QString::fromStdString(class_object_->get_interpretation());
        ui->interpretation_label->setText(interpretation);
    }else {
        ui->interpretation_label->setText("-");
    }
}

// Create and connect actions.
void MainWindow::createActions() {

    // Dropdown menu actions
    reset_act = new QAction(tr("&Reset"), this);
    connect(reset_act, &QAction::triggered, this, &MainWindow::reset);

    quit_act = new QAction(tr("&Quit"), this);
    connect(quit_act, &QAction::triggered, this, &MainWindow::quit);

    female_act = new QAction(tr("&Female"), this);
    female_act->setCheckable(true);
    connect(female_act, &QAction::triggered, this, &MainWindow::set_female);

    male_act = new QAction(tr("&Male"),this);
    male_act->setCheckable(true);
    connect(male_act, &QAction::triggered, this,&MainWindow::set_male);

    // Height and weight change actions
    connect(ui->height_slider, &QSlider::valueChanged,this, &MainWindow::set_height);
    connect(ui->height_slider, &QSlider::valueChanged, this, &MainWindow::calculate_bmi);
    connect(ui->height_slider, &QSlider::valueChanged, this, &MainWindow::interpret);

    connect(ui->weight_slider, &QSlider::valueChanged,this, &MainWindow::set_weight);
    connect(ui->weight_slider, &QSlider::valueChanged, this, &MainWindow::calculate_bmi);
    connect(ui->weight_slider, &QSlider::valueChanged, this, &MainWindow::interpret);

    // Create action group for Gender dropdown.
    gender_group = new QActionGroup(this);
    gender_group->addAction(female_act);
    gender_group->addAction(male_act);
    female_act->setChecked(true);
}

// Create dropdown menus.
void MainWindow::createMenus() {
    action_menu = menuBar()->addMenu(tr("&Action"));
    action_menu->addAction(reset_act);
    action_menu->addAction(quit_act);

    gender_menu = menuBar()->addMenu(tr("&Gender"));
    gender_menu->addAction(female_act);
    gender_menu->addAction(male_act);


}





