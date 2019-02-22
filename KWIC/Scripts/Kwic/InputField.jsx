class InputField extends React.Component {

    constructor() {
        super();
        this.state= {
            input: "",
            list: []
        }
    };

    updateInputValue = (e) => {
        this.setState ({
            input: e.target.value
        })
    }
    onAdd = (e) => {
        e.preventDefault();
        e.stopPropagation();
        let tempList = this.state.list;
        tempList.push(this.state.input);
        this.setState({
            list: tempList
        })
    }
    renderLineField = () => {
        return (
            <LineField list={this.state.list}/>
        )
    }
    render() {
        return(
            <div>
                <form className="row">
                    <input 
                        className="col-sm-10"
                        onChange={e => this.updateInputValue(e)}
                    >
                    </input>
                    <button 
                        className="col-sm-2 button"
                        onClick={this.onAdd}
                    >
                        Add
                    </button>
                </form>
                {this.renderLineField()}
            </div>
        )
    }
}

