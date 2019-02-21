#include<iostream>
#include"HashNode.h"

using namespace std;

class DeletedNode :public HashNode {
private:
	static DeletedNode *entry;
	DeletedNode();
public:
	static DeletedNode *getNode();
};

DeletedNode::DeletedNode() :HashNode(-1, -1) {}

DeletedNode * DeletedNode::getNode()
{
	if (entry == NULL) {
		entry = new DeletedNode();
	}
	return entry;
}
;

DeletedNode *DeletedNode::entry = NULL;
