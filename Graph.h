#pragma once

#include "Node.h"

namespace graphAR
{
	struct HelperDataAStar
	{
		double heuristicDistance;
		double shortestDistanceFromStart = std::numeric_limits<double>::infinity();
		double totalDistance = std::numeric_limits<double>::infinity();
		unsigned int previousNode = std::numeric_limits<double>::infinity();
		bool visited = false;
	};

	class Graph
	{
	public:
		bool AddNode(unsigned int nodeID);
		bool AddRelation(unsigned int startingNodeID, unsigned int destinationNode, double wage);
		[[nodiscard]] std::vector<unsigned int> GetNodeIDs() const;

		void PrintNodes();
		bool SearchPathAStar(
			unsigned int startingNode,
			unsigned int finishNode,
			const std::unordered_map<unsigned int, double> heuristicDistances,
			std::vector<unsigned int>& path);

	private:
		std::unordered_map<unsigned int, std::shared_ptr<Node>> nodes;
	};
} // namespace graphAR
