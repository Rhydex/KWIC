class Alphabetizer extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            list: this.props.list || []
        }
    }
    render() {
        return(
            <div>
                <OutputField list={this.state.list} />
            </div>
            
        )
    }
}