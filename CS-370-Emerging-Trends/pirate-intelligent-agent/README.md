# CS 370: Current and Emerging Trends in Computer Science
## Autonomous Deep Q-Learning Pathfinding Agent

![Python](https://img.shields.io/badge/Python-3.10+-blue.svg)
![TensorFlow](https://img.shields.io/badge/TensorFlow-2.x-orange.svg)
![Keras](https://img.shields.io/badge/Keras-Deep%20Learning-red.svg)
![Jupyter](https://img.shields.io/badge/Notebook-Jupyter-F37626.svg)

---

## Project Overview

This project implements an autonomous pathfinding agent (the "Pirate") inside an $8 \times 8$ grid-world maze using Deep Q-Learning (DQN). The objective of the agent is to find the optimal, shortest path from any valid free starting cell to the target treasure located at the bottom-right corner of the environment, navigating around static obstacles and avoiding boundary penalties.

### Architecture & Work Breakdown

#### 1. Provided Infrastructure
* **Environment (`TreasureMaze.py`):** Represents the $8 \times 8$ matrix world, defining valid actions (`Left`, `Up`, `Right`, `Down`), environmental state observation vectors, boundary checks, and reward allocations ($+1.0$ for treasure, $-0.75$ for obstacles, $-0.80$ for out-of-bounds, $-0.04$ per transition).
* **Experience Buffer Skeleton (`GameExperience.py`):** Provides the foundation for memory storage and batch extraction to support experience replay.
* **Model Scaffold:** Sequential neural network architecture with two hidden `Dense` layers (64 units each) and `PReLU` activations compiled using Adam and Mean Squared Error (MSE).

#### 2. Developed Implementation (`qtrain`)
* **Dynamic Epsilon-Greedy Strategy:** Programmed exploration vs. exploitation trade-offs, starting with $\epsilon = 1.0$, decaying exponentially at a factor of $0.995$ down to a base threshold of $0.05$ once consistency was established.
* **Experience Replay Pipeline:** Captured state transitions $(s, a, r, s', \text{status})$ into circular replay memory to decouple sequential step correlation during minibatch updates (`batch_size = 32`).
* **Target Network Synchronization:** Cloned and updated target model weights periodically (`target_update_freq = 50`) to stabilize temporal difference target calculations.
* **Randomized State Generalization:** Placed the agent at random free cells across the maze for each epoch, ensuring global pathfinding convergence rather than over-fitting to a single static starting coordinate.
* **Automated Completion Verification:** Integrated full-grid validation (`completion_check()`) verifying a 100% win rate across all starting points, achieving convergence at **Epoch 576**.

---

## Computer Science Reflection & Connections

### What Computer Scientists Do and Why It Matters
Computer scientists design computational models, algorithms, and architectures that transform raw data and theoretical logic into functional, automated solutions. Beyond writing syntax, computer science is about modeling complex real-world phenomena—from logistical route optimization and network resource allocation to autonomous robotics and decision-support systems. 

Reinforcement learning illustrates the power of this discipline: instead of hard-coding deterministic rule-sets for every possible state, computer scientists build adaptive learning mechanisms that allow software to infer optimal strategies directly from environmental feedback. This work matters because it creates resilient systems capable of operating efficiently in uncertain, non-static conditions where traditional deterministic algorithms fall short.

### How I Approach Problems as a Computer Scientist
Approaching complex engineering challenges requires a structured, multi-stage methodology:
1. **Problem Decomposition & Modeling:** Breaking down high-level objectives into modular components (e.g., mapping a pathfinding game into a Markov Decision Process with clear state vectors, action spaces, and mathematical reward penalties).
2. **Algorithm Selection & Abstraction:** Evaluating trade-offs between value-based, policy-based, and hybrid architectures based on problem constraints (e.g., choosing Deep Q-Networks for discrete grid spaces vs. Actor-Critic methods for continuous environments).
3. **Iterative Diagnostics & Refactoring:** Systematically isolating bottlenecks—such as mitigating the "dying ReLU" problem with `PReLU` activations, stabilizing moving targets with dual-network architectures, or identifying local development bottlenecks and transitioning from constrained cloud sandboxes to optimized local execution environments.
4. **Validation & Proof of Concept:** Ensuring that empirical success (such as a temporary high win rate) is thoroughly verified against formal completion criteria across all possible test parameters.

### Ethical Responsibilities to the End User and Organizations
As software systems become increasingly autonomous, a computer scientist's ethical responsibility extends far beyond raw algorithmic efficiency:
* **Safety & Alignment (Preventing Reward Hacking):** Reinforcement learning models are optimized strictly to maximize rewards. Without rigorous constraints and guardrails, systems can exploit unintended loopholes (e.g., reward gaming or unauthorized sandbox boundary escapes). Developers must ensure that objective functions align with the intended spirit of safety, including programming systems to accept suboptimal outcomes rather than breaching operational boundaries.
* **Transparency & Explainability (XAI):** Developers must work to demystify "black box" neural network layers. Stakeholders and end users require clear, accessible insight into how models make decisions, especially in critical domains like healthcare, finance, or automated operations.
* **Data Privacy & User Autonomy:** Designing AI solutions—such as context-aware productivity systems or autonomous agents—demands strict adherence to data governance. Incorporating localized execution (local LLMs / on-device processing) and transparent, active consent mechanisms ensures that user privacy and organizational security are treated as foundational requirements rather than afterthoughts.

---

## How to Run Locally

### Prerequisites
* Python 3.10+
* Jupyter Notebook or VS Code Jupyter Extension

### Installation & Execution

```bash
# Clone the repository
git clone [https://github.com/Lazeruth/CS-Portfolio.git](https://github.com/Lazeruth/CS-Portfolio.git)

# Navigate to the project directory
cd CS-Portfolio/CS-370-Emerging-Trends/pirate-intelligent-agent/

# Install the required dependencies
pip install -r requirements.txt

# Launch the notebook
jupyter notebook TreasureHuntGame_starterCode.ipynb
