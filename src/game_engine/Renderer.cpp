#include "Renderer.h"
#include "Mesh.h"
#include "Material.h"
#include "Entity.h"
#include "Camera.h"
#include "Transform.h"

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

		material->internalShader->setUniform("u_Projection", GetEngine()->GetCamera()->GetProjection());
		material->internalShader->setUniform("u_Model", GetEntity()->GetComponent<Transform>()->GetModel());
		material->internalShader->setUniform("u_View", GetEngine()->GetCamera()->GetView());

		material->internalShader->render();
	}

	void Renderer::SetMesh(std::shared_ptr<Mesh> _mesh)
	{
		mesh = _mesh;
	}

	void Renderer::SetMaterial(std::shared_ptr<Material> _mat)
	{
		material = _mat;
	}
}

