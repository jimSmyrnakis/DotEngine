using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using UnityEngine;

public class Ty_Handler : MonoBehaviour
{
    Animator anm_c = null;

    // Start is called before the first frame update
    void Start()
    {
        anm_c = GetComponent<Animator>();
    }

    //Update is called once per frame
    void Update()
    {
        if (Input.GetKey("right"))
        {
            anm_c.SetInteger("option", 1);
        }
        else if (Input.GetKey("left"))
        {
            anm_c.SetInteger("option", 0);
        }
        
        if (Input.GetKey("space"))
        {
            anm_c.SetTrigger("jump");
        }
    }
}


