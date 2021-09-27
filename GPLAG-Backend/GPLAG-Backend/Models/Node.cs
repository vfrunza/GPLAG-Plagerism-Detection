
namespace GPLAG_Backend.Models;
public class Node
{
    private enum Type
    {
        CallSite,
        Control,
        Declaration,
        Assignment,
        Increment,
        Return,
        Expression,
        Jump,
        Label,
        SwitchCase
    }
}
