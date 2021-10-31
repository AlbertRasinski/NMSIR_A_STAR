#pragma once

#include "Node.h"
#include <iostream>
#include <memory>

namespace graphAR
{
	class Node;

	class Edge
	{
	public:
		Edge(std::shared_ptr<Node> destinationNode, double wage);
		[[nodiscard]] double GetWage() const;
		[[nodiscard]] std::shared_ptr<Node> GetDestinationNode() const;

	private:
		std::shared_ptr<Node> destinationNode;
		double wage;
	};
} // namespace graphAR
