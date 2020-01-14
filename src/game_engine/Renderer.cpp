#include "Renderer.h"
#include "Mesh.h"
#include "Material.h"
#include "Entity.h"
#include "Camera.h"
#include "Transform.h"
#include "Texture.h"

namespace game_engine
{
	void Renderer::OnInit()
	{
		window = GetEngine()->GetWindow();
		context = GetEngine()->GetContext();
	}

	void Renderer::OnDisplay()
	{
		material->internalShader->setMesh(mesh->internalMesh);
		if (texture != NULL)
		{
			mesh->internalMesh->setTexture("u_Texture", texture->internalTexture);
		}

		material->internalShader->setUniform("u_Projection", GetEngine()->GetCamera()->GetProjection());
		material->internalShader->setUniform("u_Model", GetEntity()->GetComponent<Transform>()->GetModel());
		material->internalShader->setUniform("u_View", GetEngine()->GetCamera()->GetView());

		material->internalShader->render();
	}

	//! \brief
	//! ```
	//!    std::shared_ptr<Renderer> renderer = ent->AddComponent<Renderer>();
	//!
	//!    std::shared_ptr<Mesh> entMesh = engine->GetResources()->Load<Mesh>("../models/Mesh");
	//!    renderer->SetMesh(entMesh);
	//! ```
	//! **
	void Renderer::SetMesh(std::shared_ptr<Mesh> _mesh)
	{
		mesh = _mesh;
	}

	//! \brief
	//! ```
	//!    std::shared_ptr<Renderer> renderer = ent->AddComponent<Renderer>();
	//!
	//!    std::shared_ptr<Material> entMaterial = engine->GetResources()->Load<Material>("../shaders/ModelShader");
	//!    renderer->SetMaterial(entMaterial);
	//! ```
	//! **
	void Renderer::SetMaterial(std::shared_ptr<Material> _mat)
	{
		material = _mat;
	}

	//! \brief
	//! ```
	//!    std::shared_ptr<Renderer> renderer = ent->AddComponent<Renderer>();
	//!
	//!    std::shared_ptr<Texture> entTexture = engine->GetResources()->Load<Texture>(""../textures/Texture"");
	//!    renderer->SetTexture(entTexture);
	//! ```
	//! **
	void Renderer::SetTexture(std::shared_ptr<Texture> _texture)
	{
		texture = _texture;
	}

	std::shared_ptr<Mesh> Renderer::GetMesh()
	{
		return mesh;
	}
}

