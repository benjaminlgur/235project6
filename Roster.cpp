#include "Roster.hpp"

Roster::Roster(){
root_ptr_ = nullptr;
} //end default construtor

Roster::Roster(Roster &copy){
    root_ptr_ = rosterCopy(copy.root_ptr_);
}

Roster::~Roster(){
    destroyRoster(root_ptr_);
}

std::shared_ptr<BinaryNode<Student>> Roster::rosterCopy(std::shared_ptr<BinaryNode<Student>> origin_root){
    std::shared_ptr<BinaryNode<Student>> new_node_ptr;
    if(origin_root != nullptr){
        new_node_ptr = std::make_shared<BinaryNode<Student>>(origin_root->getItem());
        new_node_ptr->setLeftChildPtr(rosterCopy(origin_root->getLeftChildPtr()));
        new_node_ptr->setRightChildPtr(rosterCopy(origin_root->getRightChildPtr()));
    }
    return new_node_ptr;
}

void Roster::destroyRoster(std::shared_ptr<BinaryNode<Student>> root_ptr){
    if(root_ptr != nullptr){
        destroyRoster(root_ptr->getLeftChildPtr());
        destroyRoster(root_ptr->getRightChildPtr());
        root_ptr.reset();
    }
}

bool Roster::isEmpty(){
    if(root_ptr_ == nullptr)
        return true;
    else if(root_ptr_ != nullptr)
        return false;
}

void Roster::add(Student &student){
    std::shared_ptr<BinaryNode<Student>> node_ptr = std::make_shared<BinaryNode<Student>>(student);
    addHelper(root_ptr_, node_ptr);
}

void Roster::add(std::vector<Student> &student_vector){
    for(Student student : student_vector){
        std::shared_ptr<BinaryNode<Student>> node_ptr = std::make_shared<BinaryNode<Student>>(student);
        addHelper(root_ptr_, node_ptr);
    }
}


std::shared_ptr<BinaryNode<Student>> Roster::addHelper(std::shared_ptr<BinaryNode<Student>> node_ptr, std::shared_ptr<BinaryNode<Student>> new_node_ptr){
    if(root_ptr_ == nullptr){
        root_ptr_ = new_node_ptr; //case of empty tree.
    }
    if(node_ptr == nullptr){
        return new_node_ptr; //base case
    }
    else {
        if(stringCompare(node_ptr->getItem().getLastName(), new_node_ptr->getItem().getLastName()) == 2){
            node_ptr->setLeftChildPtr(addHelper(node_ptr->getLeftChildPtr(), new_node_ptr));
        }
        if(stringCompare(node_ptr->getItem().getLastName(), new_node_ptr->getItem().getLastName()) == 1){
            node_ptr->setRightChildPtr(addHelper(node_ptr->getRightChildPtr(), new_node_ptr));
        }
        if(stringCompare(node_ptr->getItem().getLastName(), new_node_ptr->getItem().getLastName()) == 0){
            if(stringCompare(node_ptr->getItem().getFirstName(), new_node_ptr->getItem().getFirstName()) == 2){
                node_ptr->setLeftChildPtr(addHelper(node_ptr->getLeftChildPtr(), new_node_ptr));
            }
            if(stringCompare(node_ptr->getItem().getFirstName(), new_node_ptr->getItem().getFirstName()) == 1){
                node_ptr->setRightChildPtr(addHelper(node_ptr->getRightChildPtr(), new_node_ptr));
            }
        }
    }
    return node_ptr;
}

int Roster::stringCompare (std::string stringOne, std::string stringTwo){
    for(int i = 0; i < stringOne.length()+stringTwo.length(); i++){
        if(stringOne == stringTwo){
            return 0;
        }
        if(stringOne[i] < stringTwo[i]){
            return 1;
        }
        else if(stringOne[i] > stringTwo[i]){
            return 2;
        }
    }
}


std::shared_ptr<BinaryNode<Student>> Roster::removeHelper(std::shared_ptr<BinaryNode<Student>> node_ptr,const Student student){
    if(node_ptr == nullptr){
        return node_ptr;
    }
    // student ==operator dosent seem to be defined. This is a work around. 
    if(node_ptr->getItem().getFirstName() == student.getFirstName() && node_ptr->getItem().getLastName() == student.getLastName()){
        node_ptr = removeNode(node_ptr);
        return node_ptr;
    }
    else{
        if (stringCompare(node_ptr->getItem().getLastName(), student.getLastName()) == 2){
            node_ptr->setLeftChildPtr(removeHelper(node_ptr->getLeftChildPtr(), student));
        }
        if (stringCompare(node_ptr->getItem().getLastName(), student.getLastName()) == 1){
            node_ptr->setRightChildPtr(removeHelper(node_ptr->getRightChildPtr(), student));
        }
        if (stringCompare(node_ptr->getItem().getLastName(), student.getLastName()) == 0){
            if (stringCompare(node_ptr->getItem().getFirstName(), student.getFirstName()) == 2){
                node_ptr->setLeftChildPtr(removeHelper(node_ptr->getLeftChildPtr(), student));
            }
            if (stringCompare(node_ptr->getItem().getFirstName(), student.getFirstName()) == 1){
                node_ptr->setRightChildPtr(removeHelper(node_ptr->getRightChildPtr(), student));
            }
        }
        return node_ptr;
    }
}


std::shared_ptr<BinaryNode<Student>> Roster::removeNode(std::shared_ptr<BinaryNode<Student>> node_ptr){
    if (node_ptr->isLeaf()){
        node_ptr.reset();
        return node_ptr;
    }
    else if(node_ptr->getLeftChildPtr() == nullptr){ //right child only
        return node_ptr->getRightChildPtr();
    }
    else if(node_ptr->getRightChildPtr() == nullptr){ //left child only
        return node_ptr->getLeftChildPtr();   
    }
    else {
        Student* new_node_value = new Student(0, "", "");
        node_ptr->setRightChildPtr(findAndRemoveLeftMostNode(node_ptr->getRightChildPtr(), *new_node_value));
        //findAndRemoveLeftMostNode(node_ptr->getRightChildPtr(), *new_node_value);
        node_ptr->setItem(*new_node_value);
        delete new_node_value;
        return node_ptr;
    }
    
}

void Roster::printStudent(std::shared_ptr<BinaryNode<Student>> node_ptr){
    std::cout << node_ptr->getItem().getID() << ", " << node_ptr->getItem().getFirstName() << ", " << node_ptr->getItem().getLastName() << std::endl;
}



void Roster::displayHelper(std::shared_ptr<BinaryNode<Student>> node_ptr){
    if(node_ptr == nullptr)
        return;
    displayHelper(node_ptr->getLeftChildPtr());
    printStudent(node_ptr);
    displayHelper(node_ptr->getRightChildPtr());
}



void Roster::display(){
    displayHelper(root_ptr_);
}


std::shared_ptr<BinaryNode<Student>> Roster::findAndRemoveLeftMostNode(std::shared_ptr<BinaryNode<Student>> start_node, Student& new_node_value){
    if(start_node->getLeftChildPtr() != nullptr){
        findAndRemoveLeftMostNode(start_node->getLeftChildPtr(), new_node_value);

    }
    new_node_value = start_node->getItem();
    start_node.reset();
    return start_node;
}

void Roster::remove(Student student){
    removeHelper(root_ptr_, student);
}

int Roster::getHeightHelper(std::shared_ptr<BinaryNode<Student>> node_ptr){
    if (node_ptr == nullptr)
        return 0;
    else
        return 1 + std::max(getHeightHelper(node_ptr->getLeftChildPtr()), getHeightHelper(node_ptr->getRightChildPtr()));
}

int Roster::getHeight(){
    return getHeightHelper(root_ptr_);
}

