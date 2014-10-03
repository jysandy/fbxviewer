#pragma once
#include <d3dapp.h>
#include <D3DException.h>
#include <CompiledShader.h>
#include <MeshData.h>
#include <DirectXMath.h>
#include <DirectXColors.h>
#include <Model.h>
#include <GeometryBufferData.h>
#include <vector>
#include <LightConstantBufferData.h>
#include <TransformConstantBufferData.h>
#include <Vertex.h>
#include <fbxsdk.h>
#include <string>
#include <stdexcept>
#include <exception>
#include <DirectXTK/Inc/WICTextureLoader.h>
#include <DirectionalLight.h>
#include <PointLight.h>
#include <Spotlight.h>
#include <NamedTexture.h>
#include <map>
#include <locale>
#include <codecvt>


namespace FBXViewer
{
	class FBXApp : public D3dtut::D3DApp
	{
	public:
		FBXApp(HINSTANCE hinstance);
		virtual ~FBXApp();

		virtual bool Init();

		virtual void UpdateScene(float dt);
		virtual void DrawScene();

	private:
		void CreateShaders();
		void CreateBuffers();
		void CreateInputLayouts();
		void CreateLights();
		void LoadModels();
		void BuildMeshes(FbxNode* child, int fileIndex);

	private:
		D3dtut::ComPtr<ID3D11Buffer> vertexBuffer;
		D3dtut::ComPtr<ID3D11Buffer> indexBuffer;
		D3dtut::ComPtr<ID3D11Buffer> transformConstantBuffer;
		D3dtut::ComPtr<ID3D11Buffer> lightConstantBuffer;
		D3dtut::ComPtr<ID3D11VertexShader> vertexShader;
		D3dtut::ComPtr<ID3D11PixelShader> pixelShader;
		D3dtut::ComPtr<ID3D11InputLayout> inputLayout;
		D3dtut::ComPtr<ID3D11Texture2D> modelTexture;
		D3dtut::ComPtr<ID3D11ShaderResourceView> shaderResourceView;
		D3dtut::ComPtr<ID3D11SamplerState> samplerState;

		D3dtut::CompiledShader compiledVS;
		D3dtut::CompiledShader compiledPS;

		std::vector<std::string> filenames;
		std::vector<std::wstring> textureFilenames;

		D3dtut::GeometryBufferData geometryBufferData;
		std::vector<D3dtut::Model> models;
		std::map<std::wstring, D3dtut::NamedTexture> textures;

		std::vector<D3dtut::DirectionalLight> dLights;
		std::vector<D3dtut::PointLight> pLights;
		std::vector<D3dtut::Spotlight> sLights;

		D3dtut::TransformConstantBufferData transformData;
		D3dtut::LightConstantBufferData lightData;
	};
}