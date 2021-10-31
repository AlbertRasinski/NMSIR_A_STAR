#include "Graph.h"

bool graphAR::Graph::AddNode(unsigned int nodeID)
{
	if (nodes.count(nodeID) != 0)
	{
		return false;
	}
	nodes[nodeID] = std::make_shared<Node>(nodeID);
	return true;
}

bool graphAR::Graph::AddRelation(unsigned int startingNodeID, unsigned int destinationNode, double wage)
{
	if (nodes.count(startingNodeID) == 0)
	{
		return false;
	}
	if (nodes.count(destinationNode) == 0)
	{
		return false;
	}
	if (wage < 0)
	{
		return false;
	}
	try
	{
		Edge edgeBetweenNodes(nodes[destinationNode], wage);
		if (!nodes[startingNodeID]->AddRelation(edgeBetweenNodes))
		{
			return false;
		};
	}
	catch (const std::invalid_argument& exception)
	{
		return false;
	}
	return true;
}

std::vector<unsigned int> graphAR::Graph::GetNodeIDs() const
{
	std::vector<unsigned int> nodeIDs;
	nodeIDs.reserve(nodes.size());
	for (const auto& [nodeID, node] : nodes)
	{
		nodeIDs.push_back(nodeID);
	}
	return nodeIDs;
}

void graphAR::Graph::PrintNodes()
{
	for (const auto& [nodeID, node] : nodes)
	{
		std::cout << "Node: " << nodeID << '\n';
		for (auto edge : node->GetRelations())
		{
			auto edgeObject = node->GetEdge(edge);
			std::cout << "  Edge: " << edge << '\t' << edgeObject.GetWage() << '\n';
		}
	}
}

bool graphAR::Graph::SearchPathAStar(
	unsigned int startingNode,
	unsigned int finishNode,
	const std::unordered_map<unsigned int, double> heuristicDistances,
	std::vector<unsigned int>& path)
{
	if (nodes.count(startingNode) == 0)
	{
		return false;
	}
	if (nodes.count(finishNode) == 0)
	{
		return false;
	}

	std::unordered_map<unsigned int, HelperDataAStar> dataAStar;
	for (const auto& [nodeID, heuristic] : heuristicDistances)
	{
		dataAStar[nodeID].heuristicDistance = heuristic;
	}

	std::vector<unsigned int> consideredNodes = { startingNode };
	auto node = nodes[startingNode];
	dataAStar[startingNode].shortestDistanceFromStart = 0.0;
	dataAStar[startingNode].totalDistance = dataAStar[startingNode].heuristicDistance;

	return false;
}
