#include <iostream>
#include <ctime>
#include <fstream>
#include "Target.h"
#include "utils.h"
#include "Rocket.h"
#include <sciplot/sciplot.hpp>

MvsCx0 table =
{
	{0.0, 0.0},
	{0.5, 0.012},
	{0.9, 0.015},
	{1.5, 0.044},
	{2.0, 0.038},
	{3.0, 0.030},
	{4.0, 0.026}
};

Engine engine(60.0, 235.0, 6.0);
AerodynamicProperties properties(0.9, 1.5, table);

std::ofstream file;
double simulationTime = 10.0;
double dt = 0.01;
double timeCount = 0.0;

Target* target = new Target(vec2(0.0, 1000.0), vec2(100.0, 0.0));
Rocket* rocket = new Rocket(vec2(1000.0, 0.0), vec2(-1.0, 0.0), 230.0, properties, engine);

std::vector<float> x_target;
std::vector<float> y_targer;

std::vector<float> x_rocket;
std::vector<float> y_rocket;

int main()
{	
	target->SetMinOverload(-9.0 * G);
	target->SetMaxOverload(9.0 * G);

	rocket->SetTarget(target);
	rocket->SetDeathRadius(15.0);

	file.open("out.txt", std::ios::out | std::ofstream::trunc);
	while (timeCount < simulationTime)
	{
		if (rocket->IsHitTarget())
		{
			std::cout << "Collision time is: " << timeCount << std::endl;
			break;
		}

		if (rocket->IsHitGround())
		{
			std::cout << "Hit the ground after: " << timeCount << std::endl;
			break;
		}

		target->Move(dt);
		rocket->Move(dt);

		if (target->GetVelocity().length() > rocket->GetVelocity().length() && rocket->GetEngine().GetEngineRunTime() < timeCount)
		{
			std::cout << "Velocity of target is greater than velocity of rocket: " << '\n'
				<< "Target velocity: " << target->GetVelocity().length() << " m/s\n"
				<< "Rocket velocity: " << rocket->GetVelocity().length() << " m/s\n"
				<< "Time is: " << timeCount << " s\n" << std::endl;
			break;
		}
		
		file << std::fixed << std::setprecision(2);
		file << "Target: ";
		target->writeLog(file);
		file << "Rocket: ";
		rocket->writeLog(file);
		file << "distance: " << rocket->distanceToTraget() << "\t";
		file << "mass: " << rocket->GetMass() << "\t";
		file << "time: " << timeCount;
		file << std::endl;

		x_target.push_back(target->GetPosition().x);
		y_targer.push_back(target->GetPosition().y);
		x_rocket.push_back(rocket->GetPosition().x);
		y_rocket.push_back(rocket->GetPosition().y);

		double radn_v = random<double>(0.0, 1.0);
		if (radn_v > 0.4 && radn_v < 0.6)
		{
			target->SetRandromAcceleration();
		}

		timeCount += dt;
	}

	file.close();
	delete target;
	delete rocket;

	sciplot::Plot plot;

	plot.xlabel("x");
	plot.ylabel("y");

	plot.legend()
		.atOutsideBottom()
		.displayHorizontal()
		.displayExpandWidthBy(0.1);

	plot.drawCurve(x_target, y_targer).label("Target");
	plot.drawCurve(x_rocket, y_rocket).label("Rocket");
	plot.show();
}
