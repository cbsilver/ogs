/**
 * Quad.cpp
 *
 *      Date: 2012/05/02
 *      Author: KR
 */

#include "Quad.h"
#include "Node.h"

#include "MathTools.h"
	
namespace MeshLib {


const unsigned Quad::_edge_nodes[4][2] =
{
	{0, 1}, // Edge 0
	{1, 2}, // Edge 1
	{0, 2}, // Edge 2
	{0, 3}  // Edge 3
};


Quad::Quad(Node* nodes[4], unsigned value)
	: Face(MshElemType::TRIANGLE, value)
{
	_nodes = nodes;
	_neighbors = new Element*[4];
	for (unsigned i=0; i<4; i++)
		_neighbors[i] = NULL;
	this->_area = this->computeArea();
}

Quad::Quad(Node* n0, Node* n1, Node* n2, Node* n3, unsigned value)
	: Face(MshElemType::TRIANGLE, value)
{
	_nodes = new Node*[4];
	_nodes[0] = n0;
	_nodes[1] = n1;
	_nodes[2] = n2;
	_nodes[3] = n3;
	_neighbors = new Element*[4];
	for (unsigned i=0; i<4; i++)
		_neighbors[i] = NULL;
	this->_area = this->computeArea();
}

Quad::Quad(const Quad &quad)
	: Face(MshElemType::QUAD, quad.getValue())
{
	_nodes = new Node*[4];
	_neighbors = new Element*[4];
	for (unsigned i=0; i<4; i++)
	{
		_nodes[i] = quad._nodes[i];
		_neighbors[i] = quad._neighbors[i];
	}
	_area = quad.getArea();
}

Quad::~Quad()
{
}

double Quad::computeArea()
{
	return MathLib::calcTriangleArea(_nodes[0]->getData(), _nodes[1]->getData(), _nodes[2]->getData())
         + MathLib::calcTriangleArea(_nodes[2]->getData(), _nodes[3]->getData(), _nodes[0]->getData());
}

}

