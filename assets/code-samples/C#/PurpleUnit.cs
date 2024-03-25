using System.Collections;
using System.Collections.Generic;
using JetBrains.Annotations;
using UnityEngine;
[CreateAssetMenu(fileName = "Purple Units", menuName = "ScriptableObjects/CreateUnit/Purple Unit", order = 1)]
public class PurpleUnit : ScriptableObject
{
    //Need to create system for counting minions of each color before spawning the waves. Need to properly name them as well.
    public GameObject newPurpleUnit;
    public string purpleUnitName;

    public Vector3[] purpleMinionSpawnLocation = { new Vector3(-44, 0.5f, -35), new Vector3(-40, 0.5f, -40), new Vector3(-35, .5f, -45) };
    public string unitType;
    public int waveSize = 3;
 
}
