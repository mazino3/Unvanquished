#ifndef DRILL_COMPONENT_H_
#define DRILL_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class DrillComponent: public DrillComponentBase {
	public:
		// ///////////////////// //
		// Autogenerated Members //
		// ///////////////////// //

		/**
		 * @brief Default constructor of the DrillComponent.
		 * @param entity The entity that owns the component instance.
		 * @param r_HumanBuildableComponent A HumanBuildableComponent instance that this component depends on.
		 * @param r_MiningComponent A MiningComponent instance that this component depends on.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		DrillComponent(Entity& entity, HumanBuildableComponent& r_HumanBuildableComponent, MiningComponent& r_MiningComponent);

		// ///////////////////// //

	private:

};

#endif // DRILL_COMPONENT_H_
