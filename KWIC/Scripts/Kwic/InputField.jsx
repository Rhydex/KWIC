class InputField extends React.Component {

    constructor() {
        super();
        this.state= {
            list: []
        }
    };

    onAdd = (e) => {
        e.preventDefault();
        e.stopPropagation();
        let input = e.currentTarget.parentElement[0].value;
        let tempList = this.state.list;
        tempList.push(input);
        this.setState({
            list: tempList
        })
    }
    render() {
        return(
            <div>
                <form className="row">
                    <input 
                        className="col-sm-10"
                    >
                    </input>
                    <button 
                        className="col-sm-2 button"
                        onClick={this.onAdd}
                    >
                        Add
                    </button>
                </form>
                <LineField list={this.state.list}/>
            </div>
        )
    }
}

