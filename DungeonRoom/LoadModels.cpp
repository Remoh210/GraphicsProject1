#include "globalOpenGLStuff.h"
#include "globalStuff.h"		// for g_pRogerRabbit

#include "cVAOMeshManager.h"
#include "cMeshObject.h"

#include "DebugRenderer/cDebugRenderer.h"

#include <iostream>

// Loading models was moved into this function
void LoadModelTypes( cVAOMeshManager* pTheVAOMeshManager, GLuint shaderProgramID )
{

	sModelDrawInfo tableInfo;
	tableInfo.meshFileName = "table.ply";					// "mig29_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(tableInfo, shaderProgramID);

	sModelDrawInfo torchInfo;
	torchInfo.meshFileName = "torch.ply";					// "mig29_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(torchInfo, shaderProgramID);

	sModelDrawInfo teapotInfo;
	teapotInfo.meshFileName = "Utah_Teapot_xyz_n.ply";			// "Utah_Teapot_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(teapotInfo, shaderProgramID);

	sModelDrawInfo terrainInfo;
	terrainInfo.meshFileName = "MeshLab_Fractal_Terrain_xyz_n.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	terrainInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(terrainInfo, shaderProgramID);
	
	sModelDrawInfo bluntInfo;
	bluntInfo.meshFileName = "blunt.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	bluntInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(bluntInfo, shaderProgramID);

	sModelDrawInfo sphereInfo;
	sphereInfo.meshFileName = "Sphere_320_faces_xyz_n.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInfo, shaderProgramID);

	sModelDrawInfo roomInfo;
	roomInfo.meshFileName = "room.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(roomInfo, shaderProgramID);

	sModelDrawInfo skullInfo;
	skullInfo.meshFileName = "skull.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	skullInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(skullInfo, shaderProgramID);

	sModelDrawInfo spiderInfo;
	spiderInfo.meshFileName = "spider.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	spiderInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(spiderInfo, shaderProgramID);

	// At this point, mesh in in GPU
	std::cout << "Mesh was loaded OK" << std::endl;

	return;
}

	
// Loads the models we are drawing into the vector
void LoadModelsIntoScene( std::vector<cMeshObject*> &vec_pObjectsToDraw )
{

	{
		cMeshObject* pTeapot = new cMeshObject();
		pTeapot->position = glm::vec3( -90.0f, 60.0f, 0.0f );
		pTeapot->objColour = glm::vec3( 0.2f, 0.8f, 0.3f );
		pTeapot->postRotation = glm::vec3(glm::radians(-20.0f), 0.0f, 0.0f);
		pTeapot->friendlyName = "teapot";
		pTeapot->meshName = "Utah_Teapot_xyz_n.ply";		
		pTeapot->setUniformScale( 0.4f );
		vec_pObjectsToDraw.push_back( pTeapot );
	}

	{
		cMeshObject* pSkull = new cMeshObject();
		pSkull->position = glm::vec3(0.0f, 50.0f, 0.0f);
		pSkull->postRotation = glm::vec3( 0.0f, glm::radians(-20.0f), 0.0f);
		pSkull->objColour = glm::vec3(1.0f, 1.0f, 1.0f);
		pSkull->friendlyName = "skull";
		pSkull->meshName = "skull.ply";		
		pSkull->setUniformScale(1.5f);
		vec_pObjectsToDraw.push_back(pSkull);
	}


	for (int count = 0; count < 3; count++) {

		cMeshObject* pSpider = new cMeshObject();
		pSpider->position = glm::vec3(80.0f, 50.0f, 0.0f);
		//pSpider->postRotation = glm::vec3(0.0f, glm::radians(-20.0f), 0.0f);
		pSpider->objColour = glm::vec3(0.24f, 0.56f, 1.0f);
		pSpider->friendlyName = "spider" + std::to_string(count);
		pSpider->meshName = "spider.ply";
		pSpider->setUniformScale(0.2f);
		vec_pObjectsToDraw.push_back(pSpider);
	}




	{
		cMeshObject* pRoom = new cMeshObject();
		pRoom->position = glm::vec3(0.0f, 0.0f, 300.0f);
		//pSpider->postRotation = glm::vec3(0.0f, glm::radians(-20.0f), 0.0f);
		pRoom->objColour = glm::vec3(0.74f, 0.86f, 1.0f);
		pRoom->friendlyName = "room";
		pRoom->meshName = "room.ply";
		pRoom->setUniformScale(50.0f);
		pRoom->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pRoom);
	}

	{
		cMeshObject* pBlunt = new cMeshObject();
		pBlunt->position = glm::vec3(0.0f, 0.0f, 300.0f);
		pBlunt->postRotation = glm::vec3(0.0f, glm::radians(-40.0f), 0.0f);
		pBlunt->objColour = glm::vec3(0.74f, 0.86f, 1.0f);
		pBlunt->friendlyName = "blunt";
		pBlunt->meshName = "blunt.ply";
		pBlunt->setUniformScale(1.0f);
		pBlunt->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pBlunt);
	}


	{
		cMeshObject* pTorch = new cMeshObject();
		pTorch->position = glm::vec3(0.0f, 0.0f, 300.0f);
		pTorch->postRotation = glm::vec3(0.0f, glm::radians(-40.0f), 0.0f);
		pTorch->objColour = glm::vec3(0.74f, 0.86f, 1.0f);
		pTorch->friendlyName = "torch";
		pTorch->meshName = "torch.ply";
		pTorch->setUniformScale(1.0f);
		pTorch->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pTorch);
	}

	{
		cMeshObject* pTable = new cMeshObject();
		pTable->position = glm::vec3( 0.0f, 0.0f, 0.0f );
		pTable->objColour = glm::vec3(  0.1f, 0.5f, 0.31f );
		pTable->setUniformScale(0.9f);
		pTable->meshName = "table.ply";	
		vec_pObjectsToDraw.push_back(pTable);
	}

	//cMeshObject* pRogerRabbit = NULL;





	{	// This sphere is the tiny little debug sphere
		cMeshObject* pDebugSphere = new cMeshObject();
		pDebugSphere->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pDebugSphere->objColour = glm::vec3(0.0f, 1.0f, 0.0f);
		float scale = 30.0f;
		pDebugSphere->friendlyName = "DebugSphere";
		pDebugSphere->nonUniformScale = glm::vec3(scale, scale, scale);
		pDebugSphere->meshName = "Sphere_320_faces_xyz_n.ply";		
		pDebugSphere->bIsWireFrame = true;
		pDebugSphere->bIsVisible = false;
		pDebugSphere->pDebugRenderer = ::g_pDebugRenderer;

		vec_pObjectsToDraw.push_back(pDebugSphere);
	}

	// ENDOF: Updated physics object





	return;
}