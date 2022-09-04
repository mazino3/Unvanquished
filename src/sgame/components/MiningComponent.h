#ifndef MINING_COMPONENT_H_
#define MINING_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class MiningComponent: public MiningComponentBase {
	public:
		// ///////////////////// //
		// Autogenerated Members //
		// ///////////////////// //

		/**
		 * @brief Default constructor of the MiningComponent.
		 * @param entity The entity that owns the component instance.
		 * @param blueprint An initialization parameter.
		 * @param r_ThinkingComponent A ThinkingComponent instance that this component depends on.
		 * @param r_TeamComponent A TeamComponent instance that this component depends on.
		 * @param r_BuildableComponent A BuildableComponent instance that this component depends on.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		MiningComponent(Entity& entity, bool blueprint, ThinkingComponent& r_ThinkingComponent, TeamComponent& r_TeamComponent, BuildableComponent& r_BuildableComponent);


		/**
		 * @brief Handle the PrepareNetCode message.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandlePrepareNetCode();

		/**
		 * @brief Handle the FinishConstruction message.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandleFinishConstruction();

		/**
		 * @brief Handle the Die message.
		 * @param killer
		 * @param meansOfDeath
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandleDie(gentity_t* killer, meansOfDeath_t meansOfDeath);

		// ///////////////////// //

		/**
		 * @brief Calculates modifier for the efficiency of one miner when another one interferes at
		 *        given distance.
		 */
		static float InterferenceMod(float distance);

		/**
		 * @brief Set whether the Miner should be active or not.
		 * @param active Whether the miner should be active.
		 */
		void SetActive(bool active);

		/**
		 * @return Whether the miner is currently mining (and interfering with other miners).
		 */
		bool Active() { return active; }

		/**
		 * @return Whether the miner is a temporary "blueprint" entity used for predictions.
		 */
		bool Blueprint() { return blueprint; }

		/**
		 * @param predict Whether to assume that the miner and its non-dead neighbors are active.
		 * @return The current or potential (if predicting) efficiency of this miner.
		 */
		float Efficiency(bool predict = false);

		/**
		 * @param predict Whether to assume that the miner and its non-dead neighbors are active.
		 * @return The current or potential (if predicting) budget gain of this miner.
		 */
		int Budget(bool predict = false);

	private:
		/**
		 * @brief Whether the miner is currently mining (and interfering with other miners).
		 */
		bool active;

		/**
		 * @brief Current efficiency.
		 */
		float currentEfficiency;

		/**
		 * @brief Efficiency under the assumption that the miner and its non-dead neighbors are active.
		 */
		float predictedEfficiency;

		/**
		 * @brief Adjust the current and calculates the predicted mining efficiency.
		 */
		void CalculateEfficiency();

		/**
		 * @brief Adjust the rate of all other mining structures in range.
		 */
		void InformNeighbors();

		/**
		 * @brief Thinking function that is called to check whether a main buildable has been
		 * 	      has been built near by.
		 */
		void Think(int timeDelta);
};

#endif // MINING_COMPONENT_H_
