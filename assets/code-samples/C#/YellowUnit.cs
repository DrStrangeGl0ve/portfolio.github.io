using System.Collections;
using System.Collections.Generic;
using UnityEngine;
[CreateAssetMenu(fileName = "Yellow Units", menuName = "ScriptableObjects/CreateUnit/Yellow Unit", order = 2)]
public class YellowUnit : ScriptableObject
{
    //Need to create system for counting minions of each color before spawning the waves. Need to properly name them as well.
    public GameObject newYellowUnit;

    public string yellowUnitName;
    //public string teamColor;


    public Vector3[] yellowMinionSpawnLocation = { new Vector3(44, 0.5f, 35), new Vector3(40, .5f, 40), new Vector3(35, .5f, 45) };
    public string unitType;
    public int waveSize = 3;
    /*public int health;
    public int attackDamage;
    public int magicDamage;
    public int attackDefense;
    public int magicResist;
    
*/
}

