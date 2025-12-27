## UE5 Project Outline
### NPC Dialogue / Interaction
- Relevant files: BP_Korok, S_Dialogue, DT_Dialogue, widget UI blueprints
- Implemented a NPC dialogue system using data tables
- The player must complete a sidequest before the dialogue is able to progress. Below is an example of how the player gets stuck on the "What are you waiting for?" line (controlled by ApplesCompleted/RepeatDialogue).
- Relevant to HW3 </br>

![yahahaha](https://github.com/user-attachments/assets/b2bdc414-f265-4657-8fe9-0d1e1d94009f)

### Bowling Game
- Simple bowling game implemented
- Player can put down a snowball (bowling ball) in the direction they were facing via right mouse click
- I intend to make this more accurate to the Snowball Bowling game at Pondo's Lodge (zelda botw) in the future.
- Relevant to bowling game assignment </br>

![bowling-ezgif com-optimize](https://github.com/user-attachments/assets/4ee020bd-dd11-4f5c-ac76-68bed43f217e)

### C++ Target Practice 
- Floating targets, C++ version of the original Targets (original target implementation can be tested in **Lvl_Room**, the project is currently defaulted to **Lvl_FirstPerson**)
- Relevant files: BP_NewTarget, C_BPAdvanced (parent class)
- Relevant to HW4 </br>

![targetvid-ezgif com-optimize](https://github.com/user-attachments/assets/7e80f601-69e3-4ddc-a2ed-f315cb0d7a7e)

### C++ Door and Button
- Door and button
- Relevant files: BP_Door, BP_Button, C_CInteractionLibrary, C_CDoor, C_CButton
![doorandbutton-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/4de49952-4bd3-45ea-8cb7-ba846709bf4b)

### NPC Fight
- NPC Fight that can be triggered by a branch in the branching dialogue with an Attack type Korok.
![npcfight-ezgif com-optimize](https://github.com/user-attachments/assets/6f5e5796-7d12-44a0-9544-7275877694d4)

### (WIP) Apples Quest
- Players are able to shoot apples through the regular left click mechanic
- I intend to implement a small mini game where players will have to meet an apple delivery quota by dropping apples in the triggerboxes of the goddess statues.
- Dialogue changes with the NPC will be triggered
<img width="1663" height="1264" alt="image" src="https://github.com/user-attachments/assets/7e105dca-9b30-4d4f-b62a-18c7119533cf" />

### Final Criteria / Attempted Points
#### Branching Dialogue (20 pts)
- Conversing with the KorokAttack gives dialogue options
#### Postprocessing (10 pts) 
- Screen turns red when health reaches 0 after triggering the NPC Fight via branching dialogue (see GIF in NPC Fight section above)
#### C++ Usage (10-30+ pts)
- The target with movements (repurposed to trigger Korok appearance)
#### Particles (10-20+ points)
- Used Niagara particle system
#### Sounds (10 points)
- BGM track
#### NPCs with subtypes (30 points)
- Korok NPC with only Yahaha! that gives you a korok seed
- Korok NPC with regular dialogue
- Korok NPC that has branching dialogue with options for NPC Fight
#### Inventory with UI (20 points)
  - Implemented simple name-based UI system for picking up items created from BP_Item
![uisystem-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/6da92724-62a6-4d5c-bab4-a1d9b900adf8)
#### Materials using custom shaders in HLSL (10 points)
  - Materials on the firefly are custom shaders in HLSL
  <img width="1919" height="1000" alt="image" src="https://github.com/user-attachments/assets/5627d72a-ac51-4493-aa85-f98f032648bb" />

#### Components and interfaces (25 points)
- Health interface
- UI Item Pickup interface
#### UI that reflects gameplay (25 points)
#### NPCs (25 points)
- Main Korok NPC with the dialogue
#### Modelling menus for (some of) the level objects (25 points)
- firefly BP is an object that was created in the modeling menu
- The eyerbrows on the Korok when the NPC attack is triggered
#### 1 complete level (25 points)
#### Main menu (25 points)
