//Name: Kimberly Guerrero
//Course: CMPR 131 - Fall 2026
//Date: November 4, 2026
//Assignment: Group Project #2 - Family Tree AVL
//Collaboration: Nick Moreno and Daniel Kim
//Resources/AI Tools Used: None

#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include <string>

class FamilyTree
{
private:
    struct Node
    {
        std::string name;
        std::string relationship;
        Node* firstChild;
        Node* nextSibling;
    };

    Node* root;
    int size;

    //search this node and its children and siblings
    Node* findMember(Node* current, const std::string& name);
    const Node* findMember(const Node* current,
                           const std::string& name) const;

    //copy this node and its children and siblings
    Node* copyTree(const Node* current);

    //delete this node and its children and siblings
    void destroyTree(Node* current);

    //display each generation with indentation
    void displayTree(const Node* current, int depth) const;

    //count this node and its children and siblings
    int countMembers(const Node* current) const;

public:
    FamilyTree();
    FamilyTree(const FamilyTree& other);
    FamilyTree& operator=(const FamilyTree& other);
    ~FamilyTree();

    //use an empty parent name to add the root
    //names must be nonempty and unique
    //return false for duplicate names or a missing parent
    bool addMember(const std::string& name,
                   const std::string& parentName,
                   const std::string& relationship);

    //remove the member and descendants but keep siblings
    //return false if the member does not exist
    bool removeMember(const std::string& name);

    //return whether the name exists
    bool searchMember(const std::string& name) const;

    void displayTree() const;

    //store the relationship in the output parameter if found
    //return false and leave the output unchanged if missing
    bool getMember(const std::string& name,
                   std::string& relationship) const;

    int getSize() const;
    bool isEmpty() const;
    void clear();
};

#endif
