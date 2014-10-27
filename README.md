hitpattern-mock
===============
There are 3 potential problems you can spot with this example:

    #1 Schema evolution not happening for TTres with splitting. See this file.
    #2 Schema evolution rules being applied multiple times for the same object. See this file
    #3 Segmentation fault releasing a TTree pointer. See comments in foo.cc.

### Schema evolution not happening

The schema evolution consist of:

- MyHitPattern(V2) has only one member and it is an array of uint.
- Convert MyHitPattern(V2) into V3 -> copy hits and increase the hit counter properly.
- Merge the two MyHitPattern that are members of MyTrack(V2) into a single MyHitPattern object which is member of MyTrack(V3).

After creating a file using v2/foo.cc and reading it with v3 you would see that:

- The split_level_0 collection is correctly transformed: Array and count will be present.
- The split_level_1 collection is partially converted, there are still two MyHitPattern objects but the count data member is present.
- The split_level_2 an default are not converted at all.

For some more information about the original schema evolution problem you can take a look at the pdf included.


### Rules begin called multiple times over the same objects

Can be triggered by clicking multiple times on the members using a TBrowser.

**There are printouts in both rules and from them you will get:**

* split_level_0 members:
    * MyHitPattern rule:
        * Count == 5 as MyTrack(V2)::hitPattern1 stores 5 hits.
        * Count == 0 as MyTrack(V2)::hitPattern2 is empty, this is totally normal and it has been done for clarity.
        * So the rule is being call just one time for each object, you can see as well that the pointers does not match betweeen runs.
    * MyTrack rule:
        * Count increases every time you click on one member, because the same object is being reused. Pointers are the same.
* split_level_1 members:
    * MyHitPattern rule:
        * Count increases: In this case you will see that the object is being reused, Pointers are the same.
    * MyTrack:
        * Count increases as well.

