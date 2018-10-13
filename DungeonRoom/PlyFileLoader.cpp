// PlyFileLoader.cpp
#include "globalStuff.h"		// g_pArrayVert and g_pArrayTris

#include <string>
#include <iostream>			// cout, cin, etc. 
#include <fstream>			// fstream 



// Actual variables in memory
// NO extern here
sPlyVertex*		g_pArrayVert = 0;	// = new sPlyTriangle[numberOfTriangles];	// HEAP
unsigned int	g_numberOfVertices = 0;
sPlyTriangle*	g_pArrayTris = 0;	// NULL NULL  nullptr
unsigned int	g_numberOfTriangles = 0;

// Load the file and place it into a temporary 
//	set of arrays (in the CPU's RAM)
bool LoadPlyFileData( std::string fileName )
{
	// Open the file that you asked.
	std::ifstream theFile( fileName.c_str() );	

	// if ( theFile.is_open() == false )
	if ( ! theFile.is_open() )			// More "c" or "C++" ish
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}
	
	// file is open OK
	std::string nextData;
	while ( theFile >> nextData )
	{
		if ( nextData == "vertex" ) 
		{
			break;		// exit while loop...
		}
	};
	// ...Jumping down to here

//	unsigned int numberOfVertices = 0;
	theFile >> g_numberOfVertices;

	std::cout << "vertices: " << g_numberOfVertices << std::endl;

	// seach for "face"
	while ( theFile >> nextData )
	{
		if ( nextData == "face" ) 
		{
			break;		// exit while loop...
		}
	};
	// ...Jumping down to here

//	unsigned int numberOfTriangles = 0;
	theFile >> g_numberOfTriangles;
	std::cout << "triangles: " << g_numberOfTriangles << std::endl;

	while ( theFile >> nextData )
	{
		if ( nextData == "end_header" ) 
		{
			break;		// exit while loop...
		}
	};
	// ...Jumping down to here


	g_pArrayVert = new sPlyVertex[g_numberOfVertices];	// HEAP

//	ZeroMemory(); win32
	// C call... (clears memory to all zeros)
	memset( g_pArrayVert, 0, sizeof( sPlyVertex ) * g_numberOfVertices );

	// Read the vertex data into the array
	for ( unsigned int index = 0; index != g_numberOfVertices; index++ )
	{
		theFile >> g_pArrayVert[index].x;
		theFile >> g_pArrayVert[index].y;
		theFile >> g_pArrayVert[index].z;

//		theFile >> g_pArrayVert[index].;
	}

	// Same with triangles

//	sPlyTriangle* pArrayTris = new sPlyTriangle[numberOfTriangles];	// HEAP
	g_pArrayTris = new sPlyTriangle[g_numberOfTriangles];	// HEAP

	memset( g_pArrayTris, 0, sizeof( sPlyTriangle ) * g_numberOfTriangles );

	int TossThisAway = 0;
	for ( unsigned int index = 0; index !=  g_numberOfTriangles; index++ )
	{
		// 3 69 1322 70
		theFile >> TossThisAway;			// 3
		theFile >> g_pArrayTris[index].vertex_index_1;
		theFile >> g_pArrayTris[index].vertex_index_2;
		theFile >> g_pArrayTris[index].vertex_index_3;
	}

	std::cout << "Read from the file OK." << std::endl;

	return true;
}


void saveLightInfo(std::string filename, std::vector<sLight*> lights)
{
	filename = "output/" + filename;
	std::string line;
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		for (std::vector<sLight*>::iterator it = lights.begin(); it != lights.end(); ++it) 
		{
			sLight* CurLight = *it;
			file << "Position_xyz: " << CurLight->position.x << " " << CurLight->position.y << " " << CurLight->position.z << "\n";
			file << "Attenuation_xyz: " << CurLight->atten.x << " " << CurLight->atten.y << " " << CurLight->atten.z << "\n";
			file << "Diffuse_rgbw: " << CurLight->diffuse.x << " " << CurLight->diffuse.y << " " << CurLight->diffuse.z << " " << CurLight->diffuse.w << "\n";
			file << "on_off: " << CurLight->param2.x << "\n";
			//pTheOneLight->AtenSphere = false;
			//LightManager->vecLights.push_back(pTheOneLight);
			//LightManager->LoadUniformLocations(program);
		}
		std::cout << "Lights information saved to " << filename.c_str() << std::endl;
		file.close();
	}
}


void LoadLightInfo(std::string filename, std::vector<sLight*> lights)
{
	filename = "output/" + filename;
	std::string line;
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		for (std::vector<sLight*>::iterator it = lights.begin(); it != lights.end(); ++it)
		{
			sLight* CurLight = *it;
			file << "Position_xyz: " << CurLight->position.x << " " << CurLight->position.y << " " << CurLight->position.z << "\n";
			file << "Attenuation_xyz: " << CurLight->atten.x << " " << CurLight->atten.y << " " << CurLight->atten.z << "\n";
			file << "Diffuse_rgbw: " << CurLight->diffuse.x << " " << CurLight->diffuse.y << " " << CurLight->diffuse.z << " " << CurLight->diffuse.w << "\n";
			file << "on_off: " << CurLight->param2.x << "\n";
			//pTheOneLight->AtenSphere = false;
			//LightManager->vecLights.push_back(pTheOneLight);
			//LightManager->LoadUniformLocations(program);
		}
		std::cout << "Lights information saved to " << filename.c_str() << std::endl;
		file.close();
	}
}

//Save Models Info to the file
void saveModelInfo(std::string filename, std::vector<cMeshObject*> models)
{
	filename = "output/" + filename;
	std::string line;
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		for (std::vector<cMeshObject*>::iterator it = models.begin(); it != models.end(); ++it)
		{
			cMeshObject* CurModel = *it;
			file << "Mesh_Name: " << CurModel->meshName << "\n";
			file << "Position: " << CurModel->position.x << " " << CurModel->position.y << " " << CurModel->position.z << "\n";
		}
		std::cout << "Models information saved to " << filename.c_str() << std::endl;
		file.close();
	}
}

//Load models Info from the file
void LoadModelInfo(std::string filename, std::vector<cMeshObject*> models)
{
	filename = "output/" + filename;
	std::string line;
	std::ifstream file(filename.c_str());
	if (file.is_open())
	{
		std::string nextData;
		while (file >> nextData)
		{
			if (nextData == "Position: ")
			{
				break;		// exit while loop...
			}
		};
	}
}