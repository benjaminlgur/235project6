//Benjamin Gur Project6 CSCI 235
#ifndef Roster_hpp
#define Roster_hpp

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
#include <string.h>

#include "BinaryNode.hpp"
#include "CourseMember.hpp"
#include "Student.hpp"
#include "Printer.hpp"
#include "Visitor.hpp"


class Roster
{
public:
    //Default Constructor for Roster
    Roster();
    
    //Copy Constructor
    Roster(Roster &copy);
    
    //Default Destructor
    ~Roster();
    
    //@return True if empty
    bool isEmpty();

    //Adds the student while maintaing BST properties. 
    void add(Student &student);

    //adds all students in the vector while maintaing BST properties.
    void add(std::vector<Student> &student_vector);

    //Removes a student.
    void remove(Student student);

    //Gets BST ADT hieght
    int getHeight();
    
    //Prints all students in order of traversal.
    void display();

    
//private:
    std::shared_ptr<BinaryNode<Student>> root_ptr_;

    //Recursive Copy constructor helper function.
    std::shared_ptr<BinaryNode<Student>> rosterCopy(std::shared_ptr<BinaryNode<Student>> origin_root);

    //Recusive destructor helper function.
    void destroyRoster(std::shared_ptr<BinaryNode<Student>> root_ptr);

    //Helper for add().
    std::shared_ptr<BinaryNode<Student>> addHelper(std::shared_ptr<BinaryNode<Student>> node_ptr, std::shared_ptr<BinaryNode<Student>> new_node_ptr);

    //@returns 0 if equal 1 if string 1 is greater alpabeticaly else 2.
    int stringCompare (std::string stringOne, std::string stringTwo);

    
    std::shared_ptr<BinaryNode<Student>> removeHelper(std::shared_ptr<BinaryNode<Student>> node_ptr,const Student student);

    std::shared_ptr<BinaryNode<Student>> removeNode(std::shared_ptr<BinaryNode<Student>> node_ptr);

    void displayHelper(std::shared_ptr<BinaryNode<Student>> node_ptr);

    void printStudent(std::shared_ptr<BinaryNode<Student>> node_ptr);

    std::shared_ptr<BinaryNode<Student>> findAndRemoveLeftMostNode(std::shared_ptr<BinaryNode<Student>> start_node, Student &new_node_value);

    int getHeightHelper(std::shared_ptr<BinaryNode<Student>> node_ptr);


};



#endif