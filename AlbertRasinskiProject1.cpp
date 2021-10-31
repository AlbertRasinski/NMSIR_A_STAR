#include "Graph.h"
#include <filesystem>
#include <fstream>
#include <string>

bool LoadGraphFromFile(const std::string& filePath, graphAR::Graph& graph, std::unordered_map<unsigned int, double> heuristicDistances)
{
	std::ifstream file;
	file.open(filePath);
	if (!file.is_open())
	{
		return false;
	}
	std::string fileLine;
	std::vector<std::pair<double, double>> points;
	std::getline(file, fileLine);
	auto pointStringIter = fileLine.begin();
	do
	{
		auto pointIter1 = std::find(pointStringIter, fileLine.end(), '(');
		if (pointIter1 == fileLine.end())
		{
			return false;
		}
		auto dotIter = std::find(pointIter1 + 1, fileLine.end(), ',');
		if (dotIter == fileLine.end())
		{
			return false;
		}
		auto pointIter2 = std::find(dotIter + 1, fileLine.end(), ')');
		if (pointIter2 == fileLine.end())
		{
			return false;
		}
		std::string xCoordinateString;
		xCoordinateString.append(pointIter1 + 1, dotIter);
		std::string yCoordinateString;
		yCoordinateString.append(dotIter + 1, pointIter2);
		try
		{
			auto xCoordinate = std::stod(xCoordinateString);
			auto yCoordinate = std::stod(yCoordinateString);
			points.emplace_back(std::make_pair(xCoordinate, yCoordinate));
		}
		catch (const std::exception& exception)
		{
			return false;
		}
		pointStringIter = pointIter2 + 1;
		if (pointStringIter == fileLine.end())
		{
			break;
		}
	} while (true);
	std::getline(file, fileLine);
	auto splitIter = std::find(fileLine.begin(), fileLine.end(), ' ');
	std::string startingPoint;
	std::string endingPoint;
	startingPoint.append(fileLine.begin(), splitIter);
	endingPoint.append(splitIter, fileLine.end());
	unsigned int start;
	unsigned int end;
	try
	{
		start = std::stoul(startingPoint);
		end = std::stoul(endingPoint);
	}
	catch (const std::exception& exception)
	{
		return false;
	}
	if (start > points.size() || end > points.size())
	{
		return false;
	}
	std::cout << start << end << '\n';
	graphAR::Graph outputGraph;
	std::unordered_map<unsigned int, double> heuristics;
	auto counter = 1u;
	for (const auto& point : points)
	{
		if (!outputGraph.AddNode(counter))
		{
			return false;
		}
		auto deltaX = points[end - 1].first - point.first;
		auto deltaY = points[end - 1].second - point.second;
		auto distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
		heuristics[counter] = distance;
		++counter;
	}
	for (unsigned int i = 1u; i <= points.size(); ++i)
	{
		std::getline(file, fileLine);
		auto wageIter = fileLine.begin();
		for (unsigned int j = 1u; j <= points.size(); ++j)
		{
			auto beforeNextWageIter = std::find(wageIter, fileLine.end(), ' ');
			std::string wageString;
			wageString.append(wageIter, beforeNextWageIter);
			double wage;
			try
			{
				wage = std::stod(wageString);
			}
			catch (const std::exception& exception)
			{
				return false;
			}
			if (wage > 0)
			{
				outputGraph.AddRelation(i, j, wage);
			}
			if (beforeNextWageIter != fileLine.end())
			{
				wageIter = beforeNextWageIter + 1;
			}
		}
	}
	graph = outputGraph;
	heuristicDistances = heuristics;
	return true;
}

int main()
{
	graphAR::Graph graph;
	LoadGraphFromFile("C:\\Users\\Albert\\Downloads\\Grafy\\2.txt", graph);
	graph.PrintNodes();
	if (5.0 < std::numeric_limits<double>::infinity())
	{
		std::cout << "fdsfsdf";
	}
	// graphAR::Graph myGraph;
	// myGraph.AddNode(1);
	// myGraph.AddNode(2);
	// myGraph.AddNode(3);
	// myGraph.AddRelation(1, 3, 5);
	// myGraph.AddRelation(1, 2, 6);
	// myGraph.AddRelation(2, 1, 7);
	// myGraph.PrintNodes();
}
