#include "Edge.h"

namespace graphAR
{
	Edge::Edge(std::shared_ptr<Node> destinationNode, double wage)
	{
		if (destinationNode == nullptr)
		{
			std::string errorMessage = "[Error] Failed to initialize edge. Invalid destination Node.";
			std::cerr << errorMessage << '\n';
			throw std::invalid_argument(errorMessage);
		}
		if (wage <= 0)
		{
			std::string errorMessage = "[Error] Failed to initialize edge. Invalid wage value.";
			std::cerr << errorMessage << '\n';
			throw std::invalid_argument(errorMessage);
		}
		this->destinationNode = destinationNode;
		this->wage = wage;
	}

	double Edge::GetWage() const
	{
		return wage;
	}

	std::shared_ptr<Node> Edge::GetDestinationNode() const
	{
		return destinationNode;
	}
} // namespace graphAR
