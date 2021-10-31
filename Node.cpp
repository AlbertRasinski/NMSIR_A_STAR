#include "Node.h"
#include <limits>

namespace graphAR
{
	Node::Node(unsigned int id) : id(id)
	{
	}

	std::vector<unsigned int> Node::GetRelations() const
	{
		std::vector<unsigned int> relationNodeIDs;
		relationNodeIDs.reserve(relations.size());
		for (const auto& [nodeID, node] : relations)
		{
			relationNodeIDs.push_back(nodeID);
		}
		return relationNodeIDs;
	}

	Edge Node::GetEdge(unsigned int destinationNodeID)
	{
		if (relations.count(destinationNodeID) == 0)
		{
			throw std::invalid_argument("da");
		}
		return relations.at(destinationNodeID);
	}

	unsigned int graphAR::Node::GetID() const
	{
		return id;
	}

	bool Node::AddRelation(const Edge& newEdge)
	{
		auto destinationNode = newEdge.GetDestinationNode();
		if (id == destinationNode->GetID())
		{
			std::cerr << "[Error] Failed to insert new edge with the id: " << destinationNode->GetID() << " to the node with the id: " << id
					  << ". Cannot insert edge to itself." << '\n';
			return false;
		}
		auto initialSize = relations.size();
		relations.emplace(std::make_pair(newEdge.GetDestinationNode()->GetID(), newEdge));
		auto finalSize = relations.size();
		if (finalSize == initialSize)
		{
			std::cerr << "[Error] Failed to insert new edge with the id: " << destinationNode->GetID() << " to the node with the id: " << id
					  << ". Edge to this node already exists." << '\n';
			return false;
		}
		return true;
	}
} // namespace graphAR
