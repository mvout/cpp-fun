
/* MainWindow class definition.
 * Defines the graphical user interface.
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "bmi.hh"

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class QAction;
class QActionGroup;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void reset();
    void quit();
    void set_female();
    void set_male();
    void set_height();
    void set_weight();
    void calculate_bmi();
    void interpret();

private:
    Ui::MainWindow *ui;

    void createActions();
    void createMenus();

    // Create new Bmi class object that
    // contains the needed variables
    // to calculate bmi.
    Bmi* class_object_ = new Bmi;

    QMenu *action_menu;
    QMenu *gender_menu;
    QActionGroup *gender_group;
    QAction *reset_act;
    QAction *quit_act;
    QAction *female_act;
    QAction *male_act;
};

#endif // MAINWINDOW_HH
