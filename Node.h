#pragma once

#include "Edge.h"
#include <memory>
#include <unordered_map>

namespace graphAR
{
	class Edge;

	class Node
	{
	public:
		Node(unsigned int id);

		[[nodiscard]] std::vector<unsigned int> GetRelations() const;
		[[nodsicard]] Edge GetEdge(unsigned int destinationNodeID);
		[[nodiscard]] unsigned int GetID() const;

		bool AddRelation(const Edge& newEdge);

	private:
		unsigned int id;
		std::unordered_map<unsigned int, Edge> relations;
	};
} // namespace graphAR
