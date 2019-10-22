public class BSTNode
{
    private String key;
    private Object value;
    private BSTNode left, right;

    public BSTNode( String key, Object value )
    {
        this.key = key;
        this.value = value;
    }

    //if key not found in BST then it is added. If jey already exists then that node's value
    //is updated.
    public void put( String key, Object value )
    {
        if ( key.compareTo( this.key ) < 0 )         
        {             
            if ( left != null )             
            {                 
                left.put( key, value );             
            }             
            else             
            {                 
                left = new BSTNode( key, value );             
            }         
        }         
        else if ( key.compareTo( this.key ) > 0 )
        {
            if ( right != null )
            {
                right.put( key, value );
            }
            else
            {
                right = new BSTNode( key, value );
            }
        }
        else
        {
            //update this one
            this.value = value;
        }
    }

    //find Node with given key and return it's value
    public Object get( String key )
    {
        if ( this.key.equals( key ) )
        {
            return value;
        }

        if ( key.compareTo( this.key ) < 0 )
        {
            return left == null ? null : left.get( key );
        }
        else
        {
            return right == null ? null : right.get( key );
        }
    }
}
